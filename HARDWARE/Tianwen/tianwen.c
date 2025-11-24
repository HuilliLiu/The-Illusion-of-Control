#include "tianwen.h"


u16 Voice_data;


void USART2_Init(u32 baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate=baud;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USART2,&USART_InitStructure);
	
	
	NVIC_InitStructure.NVIC_IRQChannel=USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART2,ENABLE);
}

void USART2_IRQHandler(void)
{
	
	//OLED显示数据
	u8 string[10]={0};
	LED=!LED;
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) 
	{
		Voice_data =USART_ReceiveData(USART2);	//读取接收到的数据
		
		//Dome
		if(Voice_data==0x62)Sign=2;//前进
		if(Voice_data==0x63)Sign=3;//后退
		if(Voice_data==0x64)Sign=4;//左转
		if(Voice_data==0x65)Sign=5;//右转
		if(Voice_data==0x66)Sign=6;//左移
		if(Voice_data==0x67)Sign=7;//右移
		if(Voice_data==0x68)Sign=8;//摇手
		if(Voice_data==0x69)Sign=9;//抖腿
		if(Voice_data==0x6a)Sign=10;//跳舞
		if(Voice_data==0x6b)Sign=22;//查询电量
		
		
		//象棋
		if(Voice_data==0x6e)Sign=20;//开始游戏
		if(Voice_data==0x6f)Sign=20;//再来一局
		
		if(Voice_data==0x31)Chess_Voice=1,Voice=1;//1号位
		if(Voice_data==0x32)Chess_Voice=2,Voice=1;//2号位
		if(Voice_data==0x33)Chess_Voice=3,Voice=1;//3号位
		if(Voice_data==0x34)Chess_Voice=4,Voice=1;//4号位
		if(Voice_data==0x35)Chess_Voice=5,Voice=1;//5号位
		if(Voice_data==0x36)Chess_Voice=6,Voice=1;//6号位
		if(Voice_data==0x37)Chess_Voice=7,Voice=1;//7号位
		if(Voice_data==0x38)Chess_Voice=8,Voice=1;//8号位
		if(Voice_data==0x39)Chess_Voice=9,Voice=1;//9号位
		
		//舵机调整
		if(Voice_data==0x71)Sign=21;//开始调整舵机
		if(Voice_data==0x72)Servo_Sign=2,Servo_Voice=1;//一号舵机加
		if(Voice_data==0x73)Servo_Sign=3,Servo_Voice=1;//一号舵机减
		if(Voice_data==0x74)Servo_Sign=4,Servo_Voice=1;//二号舵机加
		if(Voice_data==0x75)Servo_Sign=5,Servo_Voice=1;//二号舵机减
		if(Voice_data==0x76)Servo_Sign=6,Servo_Voice=1;//三号舵机加
		if(Voice_data==0x77)Servo_Sign=7,Servo_Voice=1;//三号舵机减
		if(Voice_data==0x78)Servo_Sign=8,Servo_Voice=1;//四号舵机加
		if(Voice_data==0x79)Servo_Sign=9,Servo_Voice=1;//四号舵机减
		if(Voice_data==0x7a)Servo_Sign=10;//结束调整舵机
		
		if(Sign != Sign_records)
		{
			Execute_once = 0;
		}
		 
		if(Voice_data==0x61||Voice_data==0x70)//立正
		{
			Sign=1;
			Time=0;
			OLED_Clear();
		}
		
		// ==== ? ??:? Sign ?? Unity ====
    USART_SendData(USART2, (u8)Sign);  
    while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
		Sign_records=Sign;//记录上一次指令
//		sprintf((char *)string,"%x",Voice_data);
//		OLED_ShowString(3,3,string,8);
//		OLED_Update();
	}
}
