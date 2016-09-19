#ifndef _PID_H_
#define _PID_H_

#include"mcuhead.h"

typedef struct {
	float P;
	float I;
	float D;
	float Bias;//ƫ��
	float Integral_Bias;//ƫ��Ļ���
	float Last_Bias;//��һ�ε�ƫ��
	float results;//������
}PIDStruct;

typedef struct {
	void(*Init)(PIDStruct *pid, float P, float I, float D);
	s16 (*PositionPID)(PIDStruct *pid,s16 Now,s16 Target);
}PIDBase;

extern const PIDBase PID;

#endif
