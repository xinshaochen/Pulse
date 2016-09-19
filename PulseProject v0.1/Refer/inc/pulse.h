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

#define AxisCount 3 //����

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
//	u32 MaxF;//����ٶ�
	ForR FR[AxisCount];//����ת
	u32 Q[AxisCount];//Ŀ��������
	
	//s32 JQ[AxisCount];//��ǰ����λ��
	s32 JEQ[AxisCount];//Ŀ�����λ��
	u8 MaxQ;//���Q������
	
}AxisData;
extern s32 JQ[];
extern float X,Y,Z;


//========================
//FIFO
#define QueueSize 200//���д�С
#define ElemType AxisData//���е���������
typedef struct
{
	u16 front;
	u16 rear;
	u16 count;
	ElemType dat[QueueSize];
}FifoQueue;
//========================


//========================
//�����������
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
