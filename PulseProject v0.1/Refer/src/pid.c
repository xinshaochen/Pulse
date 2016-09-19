#include"PID.h"

static void Init(PIDStruct *pid,float P,float I,float D)
{
	pid->Bias=pid->Integral_Bias=pid->Last_Bias=pid->results=0;
	pid->P = P;
	pid->I = I;
	pid->D = D;
}

/**************************************************************************
�������ܣ�λ��ʽPID������
��ڲ���������������λ����Ϣ��Ŀ��λ��
����  ֵ�����PWM
����λ��ʽ��ɢPID��ʽ 
pwm=Kp*e(k)+Ki*��e(k)+Kd[e��k��-e(k-1)]
e(k)������ƫ�� 
e(k-1)������һ�ε�ƫ��  
��e(k)����e(k)�Լ�֮ǰ��ƫ����ۻ���;����kΪ1,2,,k;
pwm�������
**************************************************************************/
static s16 PositionPID(PIDStruct *pid,s16 Now,s16 Target) 
{
	 pid->Bias=Now-Target;                                  //����ƫ��
	 pid->Integral_Bias+=pid->Bias;	                                 //���ƫ��Ļ���
	 pid->results=pid->P*pid->Bias+pid->I*pid->Integral_Bias+pid->D*(pid->Bias-pid->Last_Bias);//λ��ʽPID������
	 pid->Last_Bias=pid->Bias;                                       //������һ��ƫ�� 
	 return pid->results;
}

const PIDBase PID = {
	Init,
	PositionPID,
};


