#include "Delta robot.h"
#include "sys.h"
#include "math.h"


#define PI 3.1415926535898

float height = 50;//高度


float DELTA_DIAGONAL_ROD = 216;//mm杆长
float DELTA_SMOOTH_ROD_OFFSET = 127.017;//mm电机轴的圆半斤
float DELTA_EFFECTOR_OFFSET = 35;//mm平台中心到杆的距离
float DELTA_CARRIAGE_OFFSET = 0;//电机轴滑块到杆的距离

#define DELTA_RADIUS (DELTA_SMOOTH_ROD_OFFSET-DELTA_EFFECTOR_OFFSET-DELTA_CARRIAGE_OFFSET)

float delta_tower1_x;//T1/T2/T3坐标位置
float delta_tower1_y;
float delta_tower2_x;
float delta_tower2_y;
float delta_tower3_x;
float delta_tower3_y;
float delta_diagonal_rod_2;//杆长平方



float delta[3];
float deltaZ[3];
//参数      半径和连杆长度
static void recalc_delta_settings(float radius,float diagonal_rod)
{
	delta_tower1_x= -sin(60*PI/180)*radius; // front left tower
	delta_tower1_y= -cos(60*PI/180)*radius;
	delta_tower2_x= sin(60*PI/180)*radius; // front right tower
	delta_tower2_y= -cos(60*PI/180)*radius;
	delta_tower3_x= 0.0; // back middle tower
	delta_tower3_y= radius;
	delta_diagonal_rod_2= pow(diagonal_rod,2);
}

static void calculate_delta(float x,float y,float z)
{
	delta[0]=sqrt(delta_diagonal_rod_2
	-pow(delta_tower1_x-x,2)
	-pow(delta_tower1_y-y,2))+z;
	delta[1]=sqrt(delta_diagonal_rod_2
	-pow(delta_tower2_x-x,2)
	-pow(delta_tower2_y-y,2))+z;
	delta[2]=sqrt(delta_diagonal_rod_2
	-pow(delta_tower3_x-x,2)
	-pow(delta_tower3_y-y,2))+z;
	
}

static void Init(void)
{
	recalc_delta_settings(DELTA_RADIUS,DELTA_DIAGONAL_ROD);
	calculate_delta(0,0,0);
	deltaZ[0]=delta[0]+height+0.005;
	deltaZ[1]=delta[1]+height+0.005;
	deltaZ[2]=delta[2]+height+0.005;
}
static void Setting(float rod,float motord,float ptorod,float htorod,float hei)
{
	DELTA_DIAGONAL_ROD=rod;
	DELTA_SMOOTH_ROD_OFFSET=motord;
	DELTA_EFFECTOR_OFFSET=ptorod;
	DELTA_CARRIAGE_OFFSET=htorod;
	height=hei;
	Init();
}




const DeltaBase Delta=
{
	Init,
	recalc_delta_settings,
	calculate_delta,
	Setting,
};

