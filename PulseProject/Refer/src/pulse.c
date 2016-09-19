//======================================================
//
//
//
//======================================================

#include "pulse.h"
#include "math.h"
#include "Delta robot.h"

#define ResetF 7000//复位速度

FifoQueue QueueAxis;
AxisData axis;
u32 MAXF=0;//最大速度
u8 MAXQ=0;//Q最大的那一轴
u8 run=0;//运动标志位

void QueueInit(FifoQueue *Queue1);


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
static void Init(void)
{
	IOInit();
	Time3Init(10-1,18-1);
	ExtiInit();
	QueueInit(&QueueAxis);
	
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
//16细分  3200一圈  单位:10um; //绝对坐标
static void AxisBuffInmm(AxisConfig *ax,Mode m)
{
	u8 i=0;
	u32 max=0;
	s32 c=0;
	MAXF=ax->MaxF;
	SetF(ax->MaxF);
	
	
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
	if(axis.JQ[MAXQ]==axis.JEQ[MAXQ])
	{
		return ;
	}
	run=1;
	TIM3->CR1|=1<<0;
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
		axis.JEQ[i]=0;
		axis.JQ[i]=0;
	}
}
static void SetXYZ(float x,float y,float z)
{
	
	x*=100;
	y*=100;
	z*=100;
		axis.JEQ[0]=x;
		axis.JQ[0]=x;
		axis.JEQ[1]=y;
		axis.JQ[1]=y;
		axis.JEQ[2]=z;
		axis.JQ[2]=z;
}
//XYZ向下一段距离
static void DownXYZ(u32 F,s32 dis)
{
	AxisConfig ax;
	ax.MaxF=F;
	ax.Q[0]=dis;
	ax.Q[1]=dis;
	ax.Q[2]=dis;
	AxisBuffInmm(&ax,OppMode);
	
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
						
							DownXYZ(ResetF,-3000);
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
						if(MAXQ!=i)
						{
							minerr[i]+=axis.Q[i];
							if(minerr[i]>axis.Q[MAXQ])
							{
								minerr[i]-=axis.Q[MAXQ];//minerr ={1 1 1 1 1 1}
								
								SetIO(i,1);
								if(axis.FR[i]==forward)
								{
									axis.JQ[i]++;
									
								}else
								{
									axis.JQ[i]--;
								}
							}
						}
					}	
					SetIO(MAXQ,1);
					if(axis.FR[MAXQ]==forward)
					{
						axis.JQ[MAXQ]++;
						if(axis.JQ[MAXQ]>=axis.JEQ[MAXQ])
						{
							run=0;
							TIM3->CR1&=~(1<<0);
							if(resetxyz==1) 
							{
								resetxyz=0;
								//ClearXYZ();
								SetXYZ(deltaZ[0],deltaZ[1],deltaZ[2]);
							}
						}
					}
					else 
					{
						axis.JQ[MAXQ]--;
						if(axis.JQ[MAXQ]<=axis.JEQ[MAXQ])
						{
							run=0;
							TIM3->CR1&=~(1<<0);
							if(resetxyz==1) 
							{
								resetxyz=0;
								//ClearXYZ();
								SetXYZ(deltaZ[0],deltaZ[1],deltaZ[2]);
							}
						}
					}					
				}
			}
			

	}
	TIM3->SR&=~(1<<0);    
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
	AxisBuffInmm,
	ConXYZ,
	ResetXYZ,
};


