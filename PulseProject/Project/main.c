#include "delay.h"
#include "led.h"
#include "sensor.h"
#include "timer.h"
#include "Uart.h"
#include "UartProtocol.h"
#include "wifi.h"
#include "pulse.h"
#include "Delta robot.h"



void GetDataEvent(UartEvent e)
{
	u8 id;
	u8 cmd;
	id=e->ReadByte();
	cmd=e->ReadByte();
	e->WriteByte(id);
	e->WriteByte(cmd);
	switch(cmd)
	{
		case All:
			e->WriteDWord(axis.JQ[axisX]);
		e->WriteDWord(axis.JQ[axisY]);
		e->WriteDWord(axis.JQ[axisZ]);
		e->WriteDWord(delta[0]*10000);
		e->WriteDWord(delta[1]*10000);
		e->WriteDWord(delta[2]*10000);
			break;
		
	}
	e->SendAckPacket();
}
u16 bufF=7000;
u8 lastid;
void SetDataEvent(UartEvent e)
{
	u8 id;
	u8 cmd;
	u8 mode;
	u8 status;
	
	
	float dcrX,dcrY,dcrZ;
	float rod,motord,ptorod,htorod,hei;
	
	
	
	AxisConfig ax;
	
	id=e->ReadByte();
	cmd=e->ReadByte();
	e->WriteByte(id);
	e->WriteByte(cmd);
	e->SendAckPacket();
	if(lastid!=id)
	{
		lastid=id;
		switch(cmd)
		{
			case EnumF:
				bufF=e->ReadWord();
				break;
			case Enumcconxyz:
				status=e->ReadByte();
			
			
			
				//Axis.ConXYZ(bufF,status);
				break;
			case EnumReset:
				Axis.ResetXYZ();
				break;
			case Enumxyz:
				
					ax.MaxF=bufF;
					mode=e->ReadByte();
					if(mode==0)
					{
						ax.Q[axisX]=e->ReadDWord();
						ax.Q[axisY]=e->ReadDWord();
						ax.Q[axisZ]=e->ReadDWord();
						Axis.AxisBuffInmm(&ax,AbsMode);
						Axis.Start();
					}else if(mode==1)
					{
						ax.Q[axisX]=e->ReadDWord();
						ax.Q[axisY]=e->ReadDWord();
						ax.Q[axisZ]=e->ReadDWord();
						Axis.AxisBuffInmm(&ax,OppMode);
						Axis.Start();
					}
				break;
			case EnumDCRxyz:
					dcrX = (s32)e->ReadDWord();
					dcrY = (s32)e->ReadDWord();
					dcrZ = (s32)e->ReadDWord();
					dcrX/=100;
					dcrY/=100;
					dcrZ/=100;
					Delta.calculate_delta(dcrX,dcrY,dcrZ);
			
					ax.MaxF=bufF;
					ax.Q[axisX]=(delta[0]+0.005)*100;
					ax.Q[axisY]=(delta[1]+0.005)*100;
					ax.Q[axisZ]=(delta[2]+0.005)*100;
					Axis.AxisBuffInmm(&ax,AbsMode);
					Axis.Start();
				break;
			case EnumSetting:
				
					rod = (s32)e->ReadDWord();
					motord = (s32)e->ReadDWord();
					ptorod = (s32)e->ReadDWord();
					htorod = (s32)e->ReadDWord();
					hei = (s32)e->ReadDWord();
			rod/=1000;
			motord/=1000;
			ptorod/=1000;
			htorod/=1000;
			hei/=1000;
					Delta.Setting(rod,motord,ptorod,htorod,hei);
				break;
			case EnumSetlow:
				
					Delta.calculate_delta(0,0,0);
					ax.MaxF=bufF;
					ax.Q[axisX]=(delta[0]+0.005)*100;
					ax.Q[axisY]=(delta[1]+0.005)*100;
					ax.Q[axisZ]=(delta[2]+0.005)*100;
					Axis.AxisBuffInmm(&ax,AbsMode);
					Axis.Start();
				break;
		}
	}
}

u8 o=0;
void tick1()
{
	AxisConfig ax;
	
	switch(o)  
	{
		case 0:
		o=1;
		Delta.calculate_delta(30,30,0);
			
					ax.MaxF=bufF;
					ax.Q[axisX]=(delta[0]+0.005)*100;
					ax.Q[axisY]=(delta[1]+0.005)*100;
					ax.Q[axisZ]=(delta[2]+0.005)*100;
					Axis.AxisBuffInmm(&ax,AbsMode);
					Axis.Start();
		break;
		case 1:
		o=2;
		Delta.calculate_delta(30,-30,0);
			
					ax.MaxF=bufF;
					ax.Q[axisX]=(delta[0]+0.005)*100;
					ax.Q[axisY]=(delta[1]+0.005)*100;
					ax.Q[axisZ]=(delta[2]+0.005)*100;
					Axis.AxisBuffInmm(&ax,AbsMode);
					Axis.Start();
		break;
		case 2:
			o=3;
		Delta.calculate_delta(-30,-30,0);
			
					ax.MaxF=bufF;
					ax.Q[axisX]=(delta[0]+0.005)*100;
					ax.Q[axisY]=(delta[1]+0.005)*100;
					ax.Q[axisZ]=(delta[2]+0.005)*100;
					Axis.AxisBuffInmm(&ax,AbsMode);
					Axis.Start();
			break;
		case 3:
			o=0;
		Delta.calculate_delta(-30,30,0);
			
					ax.MaxF=bufF;
					ax.Q[axisX]=(delta[0]+0.005)*100;
					ax.Q[axisY]=(delta[1]+0.005)*100;
					ax.Q[axisZ]=(delta[2]+0.005)*100;
					Axis.AxisBuffInmm(&ax,AbsMode);
					Axis.Start();
			break;
	}
	
}

int main(void)
{
	AxisConfig ax;
	
	Stm32_Clock_Init(9);
	JTAG_Set(1);
	
	Timer.Init(72);
	delay_init(72);
	Axis.Init();
	
	
	Delta.Init();
	
	
	UART.Init(72,115200,OnRecvData);
	UART.SendByte(0);
	
	
	
	UartProtocol.Init(buffdata);
	UartProtocol.AutoAck(ENABLE);
//===========================================================
//wifi����
	UartProtocol.RegisterCmd(Alive,wifi.uart.AliveEvent);
	UartProtocol.RegisterCmd(DeErr,wifi.uart.DeErrEvent);
	UartProtocol.RegisterCmd(sendMeIP,wifi.uart.SendMeIPEvent);
	Timer.Start(5,UartProtocol.Check);
	Timer.Start(100,wifi.Task.sendServing);
//===========================================================
	UartProtocol.RegisterCmd(GetData,GetDataEvent);
	UartProtocol.RegisterCmd(SetData,SetDataEvent);
	
//Axis.ResetXYZ();
//delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);


//Timer.Start(1500,tick1);

	while(1)
	{
		Timer.Run();
	}
	

	
	
}
