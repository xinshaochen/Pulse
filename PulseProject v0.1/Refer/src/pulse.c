//======================================================
//
//
//
//======================================================

#include "pulse.h"
#include "math.h"
#include "Delta robot.h"
#include "string.h"

#define ResetF 7000//复位速度
#define DownDistances -3000//复位向下距离

FifoQueue QueueAxis;
float X,Y,Z;//当前位置
u32 MAXF=0;//最大速度
u8 MAXQ=0;//Q最大的那一轴
u8 run=0;//运动标志位

s32 JQ[AxisCount];//当前绝对位置
AxisData axis;//当前的执行数据


//s32 JEQ[AxisCount];//当前的目标位置


static void IOInit()
{
	RCC->APB2ENR|=1<<4;
	GPIOC->CRL&=0xff000000;
	GPIOC->CRL|=0x00333333;
	PWM1=0;
	PWM2=0;
	PWM3=0;
	DIR1=0;
	DIR2=0;
	DIR3=0;
}
static void Time3Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;	
	TIM3->ARR=arr; 
	TIM3->PSC=psc;  
	TIM3->DIER|=1<<0;
	TIM3->CR1&=~(1<<0);
	MY_NVIC_Init(1,3,TIM3_IRQn,2);
}
static void ExtiInit()
{
	RCC->APB2ENR|=1<<6;//E
	GPIOE->CRL&=0xfffff000;
	GPIOE->CRL|=0x00000888;
	GPIOE->ODR|=7<<0;
	
	Ex_NVIC_Config(GPIO_E,0,RTIR);
	Ex_NVIC_Config(GPIO_E,1,RTIR);
	Ex_NVIC_Config(GPIO_E,2,RTIR);
	
	MY_NVIC_Init(2,2,EXTI2_IRQn,2);
	MY_NVIC_Init(2,1,EXTI1_IRQn,2);
	MY_NVIC_Init(2,0,EXTI0_IRQn,2);
	
}

void (*Conversion)(float x,float y,float z);
void ClearXYZ();
static void Init(ConversionCallBack function)
{
	Conversion = function;
	IOInit();
	Time3Init(10-1,18-1);
	ExtiInit();
	QueueInit(&QueueAxis);
	ClearXYZ();
	memset((char *)&axis,0,sizeof(axis));
	
}
//设置频率
static void SetF(u32 F)
{
	TIM3->ARR = (2000000/F)-1;
	TIM3->CCR1 = TIM3->ARR;
}
//设置PWMIO
static void SetIO(u8 i,u8 st)
{
	switch(i)
	{
		case 0:
			PWM1=st;
			break;
		case 1:
			PWM2=st;
			break;
		case 2:
			PWM3=st;
			break;
	}
}
//设置方向IO
static void SetDir(u8 i,u8 dir)
{
	switch(i)
	{
		case 0:
			DIR1=dir;
			break;
		case 1:
			DIR2=dir;
			break;
		case 2:
			DIR3=dir;
			break;
	}
}
//绝对值
u32 abs32(s32 num)
{
	return num>0?num:-num;
}





#define delta_segments_per_second 1
float feedrate=1,feedmultiply=1;//进给速度和进给倍率
static void AxisGcode(GcodeBase Gcode,float x,float y,float z)
{
	AxisConfig ax;
	u16 i,l;
	
	float difference[AxisCount];//存放XYZ目标距离与当前距离的差
	float destination[AxisCount];
	float current_position[AxisCount];//存放当前位置
	float cartesian_mm;//直线距离
	float seconds;
	int steps;//分割次数
	float fraction;
	
	
	switch(Gcode)
	{
		case G0:
		Conversion(x,y,z);
		for(i=0;i<AxisCount;i++)
		{
			ax.Q[i] = (delta[i]+0.005)*100;
		}
		Axis.AxisBuffInmm(&ax);
		X=x;Y=y;Z=z;
			break;
		case G1:
		current_position[axisX]=X;
		current_position[axisY]=Y;
		current_position[axisZ]=Z;
		difference[axisX]=x-X;
		difference[axisY]=y-Y;
		difference[axisZ]=z-Z;
		cartesian_mm=sqrt(pow(difference[axisX],2)+
		pow(difference[axisY],2)+
		pow(difference[axisZ],2));
		if(cartesian_mm<0.01) return ;
		seconds=/*6000**/cartesian_mm/feedrate/feedmultiply;
		steps=1>delta_segments_per_second*seconds?1:delta_segments_per_second*seconds;//max(1,(int)delta_segments_per_second*seconds);
		for(i=1;i<=steps;i++)
		{
			fraction = (float)i/steps;
			for(l=0;l<AxisCount;l++)
			{
				destination[l]=current_position[l]+difference[l]*fraction;
			}
			Conversion(destination[axisX],destination[axisY],destination[axisZ]);
			for(l=0;l<AxisCount;l++)
			{
				ax.Q[l] = (delta[l]+0.005)*100;
			}
			while( Axis.AxisBuffInmm(&ax)==QueueFull);
		}
		
		
		X=x;Y=y;Z=z;

			break;
		default:break;
	}
}
u8 dirMove=0;
float moveDis=1;
//0不动 1前 2前右 3右....
static void AxisDirMove(u8 dir,float moveDistance)
{
	
	float x=X,y=Y,z=Z;
//	s32 c;
//	u8 i;
//	u32 max=0;
//
	moveDis=moveDistance;
	dirMove = dir;
	switch(dir)
	{
		case 0:
			break;
		case 1:
			y+=moveDistance;
			break;
		case 2:
			y+=moveDistance;
			x+=moveDistance;
			break;
		case 3:
			x+=moveDistance;
			break;
		case 4:
			y-=moveDistance;
			x+=moveDistance;
			break;
		case 5:
			y-=moveDistance;
			break;
		case 6:
			x-=moveDistance;
			y-=moveDistance;
			break;
		case 7:
			x-=moveDistance;
			break;
		case 8:
			y+=moveDistance;
			x-=moveDistance;
			break;
		case 9:
			z+=moveDistance;
			break;
		case 10:
			z-=moveDistance;
			break;
	}		
	if(x>50||x<-50||y>50||y<-50)
	{
		dirMove=0; 
		return ;
	}
	AxisGcode(G0,x,y,z);
}


void Start(void);
static u8 s=0;
//绝对模式下的  填充buff区。
static QueueErr AxisBuffInmm(AxisConfig *ax)
{
	AxisData axisd;
	u8 i;
	u32 max=0;
	s32 c=0;
	u16 rear;//队列倒数第二个数据
	QueueErr err;
	
	if((QueueAxis.front == QueueAxis.rear) && (QueueAxis.count == QueueSize))
	{
		return QueueFull;
	}
		
	if(QueueAxis.rear==0) rear = QueueSize-1;
	else rear=QueueAxis.rear-1;
	
	//axisd.MaxF=ax->MaxF;
	for(i=0;i<AxisCount;i++)
	{
		if(QueueAxis.count==0)
		{
			c=ax->Q[i]-axis.JEQ[i];
		}else
		{
			c=ax->Q[i]-QueueAxis.dat[rear].JEQ[i];
		}
		axisd.JEQ[i]=ax->Q[i];
		axisd.Q[i]=abs32(c);
		if(c>=0)
		{
			axisd.FR[i]=forward;
		}else
		{
			axisd.FR[i]=reversal;
		}
	}
	
	max=axisd.Q[0];
		axisd.MaxQ=0;
		for(i=0;i<AxisCount;i++)
		{
			if(max < axisd.Q[i])//求最大轴
			{
				max = axisd.Q[i];
				axisd.MaxQ = i;
			}	
		}
	
	err = QueueIn(&QueueAxis,axisd);	
	if(run==0)
	{
		Start();
	}
	return err;
}
//16细分  3200一圈  单位:10um; //绝对坐标
static void AxisGomm(AxisConfig *ax,Mode m)
{
	u8 i=0;
	u32 max=0;
	s32 c=0;
//	MAXF=ax->MaxF;
//	SetF(ax->MaxF);
	
	
	if(m==AbsMode)
	{
		for(i=0;i<AxisCount;i++)
		{
	//=======================================
			//绝对
			
			c=ax->Q[i]-axis.JEQ[i];
			axis.JEQ[i]=ax->Q[i];
			axis.Q[i]=abs32(c);
			if(c>=0)//正数正转//绝对坐标
			{
				axis.FR[i]=forward;
			}else
			{
				axis.FR[i]=reversal;
			}
		}
			
		max=axis.Q[0];
		MAXQ=0;
		for(i=0;i<AxisCount;i++)
		{
			if(max < axis.Q[i])//求最大轴
			{
				max = axis.Q[i];
				MAXQ = i;
			}	
		}
		
	}
	else if(m==OppMode)
	{
		for(i=0;i<AxisCount;i++)
		{
		//相对
			axis.Q[i]=abs32(ax->Q[i]);
			axis.JEQ[i]+=ax->Q[i];
			
			if(ax->Q[i]>=0)
			{
				axis.FR[i]=forward;
			}else
			{
				axis.FR[i]=reversal;
			}		
		}
		max=axis.Q[0];
		MAXQ=0;
		for(i=0;i<AxisCount;i++)
		{
			if(max < axis.Q[i])//求最大轴
			{
				max = axis.Q[i];
				MAXQ = i;
			}	
		}
//========================================		
	}

}


//开始运行
static void Start(void)
{
	if(QueueAxis.count>0)
	{
		QueueOutSetting(&QueueAxis,&axis);
		if(JQ[MAXQ]==axis.JEQ[MAXQ])
		{
			return ;
		}
		run=1;
		TIM3->CR1|=1<<0;
	}
}
//停止运行
static void Stop(void)
{
	run=0;
	TIM3->CR1&=~(1<<0);
}
u8 Constatus=0;
//连续运动 
//st  bit0,是否运动 bit1,1轴正反转 bit2,1轴是否运动
static void ConXYZ(u32 maxF,u8 st)
{
	SetF(maxF);
	Constatus=st;
	if(st&0x01)
	{
		run=1;
		TIM3->CR1|=1<<0;
	}else
	{
		run=0;
		TIM3->CR1&=~(1<<0);
	}
}
u8 resetxyz=0;
//复位
static void ResetXYZ()
{
	u8 i=0;
	resetxyz=1;
	ConXYZ(ResetF,0x55);//运动
}
//清除XYZ值
static void ClearXYZ()
{
	u8 i=0;
	for(i=0;i<AxisCount;i++)
	{
		//axis.JEQ[i]=0;
		JQ[i]=0;
	}
}
static void SetXYZ(float x,float y,float z,float d1,float d2,float d3)
{
	d1=(d1+0.005)*100;
	d2=(d2+0.005)*100;
	d3=(d3+0.005)*100;
	X=x;
	Y=y;
	Z=z;
		axis.JEQ[0]=d1;
		JQ[0]=d1;
		axis.JEQ[1]=d2;
		JQ[1]=d2;
		axis.JEQ[2]=d3;
		JQ[2]=d3;
}
//XYZ向下一段距离
static void DownXYZ(u32 F,s32 dis)
{
	AxisConfig ax;
//	ax.MaxF=F;
	SetF(F);
	ax.Q[0]=dis;
	ax.Q[1]=dis;
	ax.Q[2]=dis;
	AxisGomm(&ax,OppMode);
	
	Start();
}

u8 xre=0;
void EXTI0_IRQHandler(void)
{
	if(XReSet==1)
	{
		xre=1;
//		axis[axisX].JQ=0;
//		axis[axisX].JEQ=0;
		Constatus&=0xFB;
	}
	EXTI->PR=1<<0;
}
u8 yre=0;
void EXTI1_IRQHandler(void)
{
	if(YReSet==1)
	{
		yre=1;
//		axis[axisY].JQ=0;
//		axis[axisY].JEQ=0;
		Constatus&=0xEF;
	}
	EXTI->PR=1<<1;	
}
u8 zre=0;
void EXTI2_IRQHandler(void)
{
	if(ZReSet==1)
	{
		zre=1;
//		axis[axisZ].JQ=0;
//		axis[axisZ].JEQ=0;
		Constatus&=0xBF;
	}
	EXTI->PR=1<<2;
}


static u8 s;
u32 minerr[AxisCount]={1,1,1};
extern float height;
void TIM3_IRQHandler(void)
{
	u8 i;
	if(TIM3->SR&0X0001)
	{
			if(s==0)
			{
				s=1;
				PWM1=0;
				PWM2=0;
				PWM3=0;
			}else
			{
				s=0;
				
				if((Constatus&0x01))//连续模式
				{
					if(Constatus&0x02)
					{
						DIR1=1;
						if(Constatus&0x04)
						{
							PWM1=1;
//							axis[axisX].JQ++;
//							axis[axisX].JEQ++;
						}
					}
					else
					{
						DIR1=0;
						if(Constatus&0x04)
						{
							PWM1=1;
//							axis[axisX].JQ--;
//							axis[axisX].JEQ--;
						}
					}	
					
					if(Constatus&0x08)
					{
						DIR2=1;
						if(Constatus&0x10)
						{
							PWM2=1;
//							axis[axisY].JQ++;
//							axis[axisY].JEQ++;
						}
					}
					else 
					{
						DIR2=0;
						if(Constatus&0x10)
						{
							PWM2=1;
//							axis[axisY].JQ--;
//							axis[axisY].JEQ--;
						}
					}
					
					
					if(Constatus&0x20)
					{
						DIR3=1;
						if(Constatus&0x40)
						{
							PWM3=1;
//							axis[axisZ].JQ++;
//							axis[axisZ].JEQ++;
						}
					}
					else
					{
						DIR3=0;
						if(Constatus&0x40)
						{
							PWM3=1;
//							axis[axisZ].JQ--;
//							axis[axisZ].JEQ--;
						}
					}
					
					
					if((!(Constatus&0x04))&&(!(Constatus&0x10))&&(!(Constatus&0x40))&&resetxyz==1)
					{
						Constatus&=0xfe;
						
							DownXYZ(ResetF,DownDistances);
					}
				}
				else
				{
					for(i=0;i<AxisCount;i++)//方向判断
					{
						if(axis.FR[i]==forward) SetDir(i,0);
						else SetDir(i,1);
						
					}

					for(i=0;i<AxisCount;i++)
					{
						if(axis.MaxQ!=i)
						{
							minerr[i]+=axis.Q[i];
							if(minerr[i]>axis.Q[axis.MaxQ])
							{
								minerr[i]-=axis.Q[axis.MaxQ];//minerr ={1 1 1}
								
								SetIO(i,1);
								if(axis.FR[i]==forward)
								{
									JQ[i]++;
									
								}else
								{
									JQ[i]--;
								}
							}
						}
					}	
					SetIO(axis.MaxQ,1);
					if(axis.FR[axis.MaxQ]==forward)
					{
						JQ[axis.MaxQ]++;
						if(JQ[axis.MaxQ]>=axis.JEQ[axis.MaxQ])
						{
							if(dirMove!=0)
							{
								AxisDirMove(dirMove,moveDis);
							//	return ;
							}
							if(QueueAxis.count>0)
							{
								QueueOutSetting(&QueueAxis,&axis);
							}else 
							{
								run=0;
								TIM3->CR1&=~(1<<0);
							}
							
							if(resetxyz==1) 
							{
								resetxyz=0;
								//ClearXYZ();
								SetXYZ(0,0,height,deltaZ[0],deltaZ[1],deltaZ[2]);
							} 
						}
					}
					else 
					{
						JQ[axis.MaxQ]--;
						if(JQ[axis.MaxQ]<=axis.JEQ[axis.MaxQ])
						{
							if(dirMove!=0)
							{
								AxisDirMove(dirMove,moveDis);
							//	return ;
							}
							if(QueueAxis.count>0)
							{
								QueueOutSetting(&QueueAxis,&axis);
							}else 
							{
								run=0;
								TIM3->CR1&=~(1<<0);
							}
							if(resetxyz==1) 
							{
								resetxyz=0;
								//ClearXYZ();
								SetXYZ(0,0,height,deltaZ[0],deltaZ[1],deltaZ[2]);
							}
						}
					}					
				}
			}
	}
	TIM3->SR&=~(1<<0);    
}

QueueErr QueueOutSetting(FifoQueue *Queue1,ElemType *sdat)
{
	u8 i;
	QueueOut(&QueueAxis,&axis);
	//SetF(axis.MaxF);
//	for(i=0;i<AxisCount;i++)
//	{
//		JEQ[i]=axis.JEQ[i];
//	}
}
//=============================================================================================================================================================
//=============================================================================================================================================================
//=============================================================================================================================================================
//FIFO队列
//Queue1 Init
void QueueInit(FifoQueue *Queue1)
{
    Queue1->front = Queue1->rear;
    Queue1->count = 0;  
}
//Queue1 In
QueueErr QueueIn(FifoQueue *Queue1,ElemType sdat) //
{
    if((Queue1->front == Queue1->rear) && (Queue1->count == QueueSize))
    {                    // full
        return QueueFull;    
    }else
    {                    // in
        Queue1->dat[Queue1->rear] = sdat;
        Queue1->rear = (Queue1->rear + 1) % QueueSize;
        Queue1->count = Queue1->count + 1;
        return QueueOperateOK;
    }
}
//Queue Out
QueueErr QueueOut(FifoQueue *Queue1,ElemType *sdat)//
{
    if((Queue1->front == Queue1->rear) && (Queue1->count == 0))
    {                    // empty
        return QueueEmpty;
    }else
    {                    // out
        *sdat = Queue1->dat[Queue1->front];
        Queue1->front = (Queue1->front + 1) % QueueSize;
        Queue1->count = Queue1->count - 1;
        return QueueOperateOK;
    }
}
//=============================================================================================================================================================
//=============================================================================================================================================================
//=============================================================================================================================================================


const AXIS Axis=
{
	Init,
	SetF,
	Start,
	Stop,
	AxisDirMove,
	AxisGcode,
	AxisBuffInmm,
	AxisGomm,
	ConXYZ,
	ResetXYZ,
	&resetxyz,
	&run,
};


