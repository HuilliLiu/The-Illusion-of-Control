#include "sys.h"
#include "delay.h"
#include "led.h"
#include "OLED.h"
#include "OLED_Content.h"
#include "OLED_Data.h"
#include "mode.h"
#include "Servo.h"
#include "tianwen.h"
#include "flash.h"
#include "adc.h"

//串口1标志,接收到A赋值1，接收到B赋值2
u8 USART1_Sign = 0;

int main(void)
{	
	u8 i;
	//OLED显示数据
	u8 string[10]={0};
	
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	delay_init();	    //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	//USART1_Init(9600);//串口1初始化
	USART2_Init(115200);
	OLED_Init();
	ADCx_Init();
	OLED_Clear();
	Store_Init();
	TIM1_Init();
	TIM2_Init(1999,719);
	TIM3_Init(1999,719);
	Servo_Control(90,1);
	Servo_Control(90,2);
	Servo_Control(90,3);
	Servo_Control(90,4);
	delay_ms(100);
	
	while(1)
	{		
		
		if(Sign==1)
		{
			Idle_task();//空闲任务
			delay_ms(950);
			i=0;
		}
		else if(Sign==2)
		{
			Forward();//前进
			
		}
		else if (Sign==3)
		{
			Backward();//后退
		}
		else if(Sign==4)
		{
			Left();//左转
		}
		else if(Sign==5)
		{
			Right();//右转
		}
		else if(Sign==6)
		{
			if(i==1)
			{
				Erase_Blink();//擦除眨眼 
				Look_left();//斜眼向左看
			}
			Shift_left();//左移
		}
		else if(Sign==7)
		{
			if(i==1)
			{
				Erase_Blink();//擦除眨眼 
				Look_left();//斜眼向左看
			}
			Shift_right();//右移
		}
		else if(Sign==8)
		{
			Shake_hands();//摇手
		}
		else if(Sign==9)
		{
			Shake_leg();//抖腿
		}
		else if(Sign==10)
		{
			Dance();//跳舞
		}

		else if(Sign==20)
		{
			Game();//下棋
			Sign=1;//空闲模式
			Time=0;//计时器清零
		}
		else if(Sign==21)
		{
			Servo_Amend();//调整舵机
		}
		else if(Sign==22)
		{
			OLED_Electricity();//显示当前电量
		}
////		
//		
//		sprintf((char *)string,"%d",Time);
//		OLED_ShowString(5,32,string,8);
//		OLED_Update();
//		
		i++;
		Vol_warn();
//		if(i%20==0)
//		{
//			LED=!LED;
//		}
		//LED=!LED;
		delay_ms(10);
	}
}


