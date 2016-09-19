#ifndef __WIFI_H
#define __WIFI_H
#include <stm32f10x.h>
#include "mcuhead.h"
#include "uart.h"
#include "uartprotocol.h"


typedef enum GetDev
{
	All,
}GetDev;
#define maxGdevEntry  3

/////////////////////////
typedef enum SetDev
{
	EnumF=0,
	Enumcconxyz,
	EnumReset,
	Enumxyz,
	EnumDCRxyz,
	EnumSetting,
	EnumSetlow,
}SetDev;
#define maxSdevEntry  4
/////////////////////////
#define maxRemoteDev 16//Զ���豸����




typedef struct
{
	u8 IP[4];
	u8 IPstr[16];
	u32 ID;
	//u8 IDstr[12];
}DevData;



extern u8 recvID;//���͵�ȷ��ID
extern u8 retRecvID;//������ȷ��ID
extern u8 recvarrayid[maxGdevEntry];
extern u8 *recvarraydata[maxGdevEntry];
extern u16 recvdatalen[maxGdevEntry];
extern u8 recvdatabit[maxGdevEntry];//���ݷ��ͱ�־λ

extern u8 sendID;//ͬ��
extern u8 retSendID;
extern u8 sendarrayid[maxSdevEntry];
extern u8 *sendarraydata[maxGdevEntry];
extern u16 senddatalen[maxGdevEntry];
extern u8 senddatabit[maxGdevEntry];//���ݷ��ͱ�־λ

extern u8 remoteDevCount;///�豸����
extern s8 SeleRemoteDev;//ѡ���豸
extern DevData remoteDev[maxRemoteDev];//Զ���豸��Ϣ
extern DevData meDev;//����

extern u8 sendIP[4];////���͵�IP
extern u8 sendIPstr[16];

extern u8 scannCount;//ɨ�����

//���ڽ����ȡIPID����
extern u8 getIPIDid;










typedef struct
{
	void (*Init)(void);
	//��ʼɨ��
	void (*ScannStart)(void);
	//��ʼ��ȡIPID
	void (*GetIPIDStart)();
	//�ͻ��˷������ݣ���Э��
	void (*ConnectSendCode)(u8 *ip,u16 port,u8 cmd,u8 *buff,u16 len);
	//�ͻ��˷������ݣ�����Э��
	void (*ConnectSend)(u8 *ip,u16 port,u8 *dat);
	///�����������ã���ȷ��
	void (*setData)(u8 sdev,u8 *dat,u16 len);
	///���ͻ�ȡ���������ȷ��
	void (*getData)(u8 gdev);
	struct
	{
		//ɨ������
		void (*ScannCmd)(void);
		//IPID����
		void (*GetIPIDCmd)(void);
	}cmd;
	struct
	{
//���ڻص�����
		void (*DeErrEvent)(UartEvent e);
		void (*AliveEvent)(UartEvent e);
		void (*SendMeIPEvent)(UartEvent e);
	}uart;
	struct
	{
//TIMER ����   ������
		void (*sendServing)();
		void (*getIPIDServing)();
	}Task;
	
}wifiBase;

extern const wifiBase wifi;




#endif
