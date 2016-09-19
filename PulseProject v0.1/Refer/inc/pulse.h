#ifndef __PULSE_H
#define __PULSE_H
#include "sys.h"

#define PWM1 PCout(0)
#define PWM2 PCout(1)
#define PWM3 PCout(2)
#define DIR1 PCout(3)
#define DIR2 PCout(4)
#define DIR3 PCout(5)

#define XReSet PEin(0)
#define YReSet PEin(1)
#define ZReSet PEin(2)

#define axisX 0
#define axisY 1
#define axisZ 2

#define AxisCount 3 //轴数

typedef enum
{
	G0=0,
	G1,
}GcodeBase;



typedef void (*ConversionCallBack)(float x,float y,float z);


typedef enum
{
	forward,
	reversal,
}ForR;

typedef struct
{
//	u32 MaxF;//最大速度
	ForR FR[AxisCount];//正反转
	u32 Q[AxisCount];//目标脉冲数
	
	//s32 JQ[AxisCount];//当前绝对位置
	s32 JEQ[AxisCount];//目标绝对位置
	u8 MaxQ;//最大Q的那轴
	
}AxisData;
extern s32 JQ[];
extern float X,Y,Z;


//========================
//FIFO
#define QueueSize 200//队列大小
#define ElemType AxisData//队列的数据类型
typedef struct
{
	u16 front;
	u16 rear;
	u16 count;
	ElemType dat[QueueSize];
}FifoQueue;
//========================


//========================
//配置入口数据
typedef struct
{
	s32 Q[AxisCount];
//	u32 MaxF;
}AxisConfig;



typedef enum
{
	AbsMode=0,
	OppMode,
}Mode;




typedef enum
{
	QueueFull,
	QueueEmpty,
	QueueOperateOK,
}QueueErr;


void QueueInit(FifoQueue *Queue1);
QueueErr QueueIn(FifoQueue *Queue1,ElemType sdat);
QueueErr QueueOut(FifoQueue *Queue1,ElemType *sdat);
QueueErr QueueOutSetting(FifoQueue *Queue1,ElemType *sdat);


typedef struct
{
	void (*Init)(ConversionCallBack function);
	void (*SetF)(u32 F);
	void (*Start)(void);
	void (*Stop)(void);
	void (*AxisDirMove)(u8 dir,float moveDistance);
	void (*AxisGcode)(GcodeBase Gcode,float x,float y,float z);
	QueueErr (*AxisBuffInmm)(AxisConfig *ax);
	void (*AxisGomm)(AxisConfig *ax,Mode m);
	void (*ConXYZ)(u32 maxF,u8 st);
	void (*ResetXYZ)(void);
	u8 *ResetS;
	u8 *State;
}AXIS;

extern const AXIS Axis;
extern AxisData axis;


#endif
