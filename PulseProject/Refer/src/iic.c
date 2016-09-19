#include "iic.h"
//=========================
//��ʼ��IIC
static void Init(void)
{					     
 	RCC->APB2ENR|=1<<3;				 
	GPIOB->CRH&=0X00FFFFFF;
	GPIOB->CRH|=0X33000000;	   
	GPIOB->ODR|=0XB<<10;     
}
//=========================
//����IIC��ʼ�ź�
static void Start(void)
{
	SDA_OUT();     //sda�����
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	delay_us(4);
 	IIC_SDA=0;//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	IIC_SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//=========================
//����IICֹͣ�ź�
static void Stop(void)
{
	SDA_OUT();//sda�����
	IIC_SCL=0;
	IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	IIC_SCL=1; 
	IIC_SDA=1;//����I2C���߽����ź�
	delay_us(4);							   	
}
//=========================
//�ȴ�Ӧ���źŵ���
static u8 Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����  
	IIC_SDA=1;delay_us(1);	   
	IIC_SCL=1;delay_us(1);	 
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			Stop();
			return 1;
		}
	}
	IIC_SCL=0;//ʱ�����0 	   
	return 0;  
} 
//=========================
//����ACKӦ��
static void Ack(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	delay_us(2);
	IIC_SCL=1;
	delay_us(2);
	IIC_SCL=0;
}
//=========================
//������ACKӦ��		    
static void NAck(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	delay_us(2);
	IIC_SCL=1;
	delay_us(2);
	IIC_SCL=0;
}
//=========================
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
static void Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    IIC_SCL=0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        IIC_SDA=(txd&0x80)>>7;
        txd<<=1; 	  
		delay_us(2);   //��TEA5767��������ʱ���Ǳ����
		IIC_SCL=1;
		delay_us(2); 
		IIC_SCL=0;	
		delay_us(2);
    }	 
} 	  
//=========================
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
static u8 Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IIC_SCL=0; 
        delay_us(2);
		IIC_SCL=1;
        receive<<=1;
        if(READ_SDA)receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        NAck();//����nACK
    else
        Ack(); //����ACK   
    return receive;
}
//=========================

/**************************ʵ�ֺ���********************************************
*����ԭ��:		unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr)
*��������:	    ��ȡָ���豸 ָ���Ĵ�����һ��ֵ
����	I2C_Addr  Ŀ���豸��ַ
		addr	   �Ĵ�����ַ
����   ��������ֵ
*******************************************************************************/ 
static unsigned char ReadOneByte(unsigned char I2C_Addr,unsigned char addr)
{
	unsigned char res=0;
	
	Start();
	Send_Byte(I2C_Addr);	   //����д����
	res++;
	Wait_Ack();
	Send_Byte(addr); res++;  //���͵�ַ
	Wait_Ack();	  
	//IIC_Stop();//����һ��ֹͣ����	
	Start();
	Send_Byte(I2C_Addr+1); res++;          //�������ģʽ			   
	Wait_Ack();
	res=Read_Byte(0);	   
    Stop();//����һ��ֹͣ����

	return res;
}

const IICBase IIC={
  Init,
  Start,
  Stop,
  Wait_Ack,
  Ack,
  NAck,
  Send_Byte,
  Read_Byte,
	ReadOneByte,
};
