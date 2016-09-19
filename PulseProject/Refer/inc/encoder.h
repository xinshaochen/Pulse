#ifndef __ENCODER_H
#define __ENCODER_H
#include "sys.h"

#define ENCODER_TIM_PERIOD (u16)(65535)   //���ɴ���65535 ��ΪF103�Ķ�ʱ����16λ�ġ�

typedef struct
{
	void (*Init)(void);
	int (*LEncoder)(void);
	int (*REncoder)(void);
}EncoderBast;
extern const EncoderBast Encoder;

#endif
