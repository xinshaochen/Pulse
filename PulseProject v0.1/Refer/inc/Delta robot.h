#ifndef __DELTA_
#define __DELTA_


typedef struct
{
	void (*Init)(void);
	void (*recalc_delta_settings)(float radius,float diagonal_rod);
	void (*calculate_delta)(float x,float y,float z);
	void (*Setting)(float rod,float motord,float ptorod,float htorod,float hei);
}DeltaBase;

extern const DeltaBase Delta;
extern float delta[];
extern float deltaZ[];
extern float height;



#endif

