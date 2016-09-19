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
	forward,
	reversal,
}ForR;

typedef struct
{
	ForR FR[AxisCount];//正反转
	u32 Q[AxisCount];//目标脉冲数
	
	s32 JQ[AxisCount];//当前绝对位置
	s32 JEQ[AxisCount];//目标绝对位置
	
}AxisData;


//========================
//FIFO
#define QueueSize 100//队列大小
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
	u32 MaxF;
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


typedef struct
{
	void (*Init)(void);
	void (*SetF)(u32 F);
	void (*Start)(void);
	void (*Stop)(void);
	void (*AxisBuffInmm)(AxisConfig *ax,Mode m);
	void (*ConXYZ)(u32 maxF,u8 st);
	void (*ResetXYZ)(void);
}AXIS;

extern const AXIS Axis;
extern AxisData axis;


#endif
