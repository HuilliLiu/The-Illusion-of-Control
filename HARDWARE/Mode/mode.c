#include "mode.h"


u16 count=0;//动作延时计数
u16 Time=0;
int Sign = 1;//指令
int Sign_records=0;//记录前一个指令
int Execute_once = 0;//某些只执行一次的指令

void TIM1_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef TIM_NVICinitStucture;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); // 时钟使能
     
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2);
	
	TIM_NVICinitStucture.NVIC_IRQChannel = TIM1_UP_IRQn; //中断通道，选择串口中断
	TIM_NVICinitStucture.NVIC_IRQChannelPreemptionPriority = 0;//配置中断优先级
	TIM_NVICinitStucture.NVIC_IRQChannelCmd	= ENABLE;//使能打开
	TIM_NVICinitStucture.NVIC_IRQChannelSubPriority	= 2;//配置中断子优先级
 
	NVIC_Init(&TIM_NVICinitStucture);//串口结构体初始化
 
	
	TIM_TimeBaseStructure.TIM_Period = 3340-1;
//设置自动重装载计数值,可以设置的值为0x0000-0xFFFF,即0到65535
//但由于从0开始计数，所以设置值=实际所需重载值-1
	TIM_TimeBaseStructure.TIM_Prescaler =7199;
//设置预分频,可以设置的值为0x0000-0xFFFF,即0到65535
//但由于没有0分频的说法，所以设置值=实际所需分频值-1
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//时钟不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseStructure.TIM_RepetitionCounter=2;   
//该参数设定溢出多少次才触发中断，可以设置的值为0x00-0xFF
//但由于从0开始计数，所以设置值=实际所需溢出次数-1           
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);//根据指定参数初始化TIMx
  TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE );
	
	
	TIM_Cmd(TIM1, ENABLE);//使能计数器
}



void TIM1_UP_IRQHandler()
{
	//OLED显示数据
	//u8 string[10]={0};
//	OLED_Clear();
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)  //判断TIM3更新中断发生与否
	{
		//LED=!LED;
		Time++;
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update  );  //清除TIMx更新中断标志 
	}
//	sprintf((char *)string,"%d",Time);
//  OLED_ShowString(5,0,string,8);
//	OLED_Update();
 
}
	


void Shake_leg(void) //抖腿
{
	delay=100;

	while(1)
	{
		count++;
		delay_us(1000);
		if(count==1)
		{
			Servo_Control(110,3);
			Servo_Control(70,4);
		}
		if(count==100)
		{
			Erase_Blink();//擦除眨眼
			Ellipse_eyes();//椭圆眼
		}
		if(count==150)
		{
			Servo_Control(90,3);
			Servo_Control(90,4);
		}
		if(count==300)
		{
			Servo_Control(100,3);
			Servo_Control(80,4);
		}
		if(count==400)
		{
			Servo_Control(90,3);
			Servo_Control(90,4);
		}
		if(count==600)
		{
			Servo_Control(110,3);
			Servo_Control(70,4);
		}
		if(count==750)
		{
			Servo_Control(90,3);
			Servo_Control(90,4);
		}
		if(count==900)
		{
			Servo_Control(100,3);
			Servo_Control(80,4);
		}
		if(count==1000)
		{
			Servo_Control(90,3);
			Servo_Control(90,4);
		}
		if(count==1200)
		{
			Servo_Control(110,3);
			Servo_Control(70,4);
		}
		if(count==1350)
		{
			Servo_Control(90,3);
			Servo_Control(90,4);
		}
		if(count==1500)
		{
			Servo_Control(100,3);
			Servo_Control(80,4);
		}
		if(count==1600)
		{
			Servo_Control(90,3);
			Servo_Control(90,4);
		}
		if(count==1800)
		{
			Servo_Control(120,1);
			Servo_Control(60,2);
		}
		if(count==2000)
		{
			Servo_Control(90,1);
			Servo_Control(90,2);
		}
		if(count>=2400)
		{
			Erase_Ellipse_eyes();//擦除椭圆眼
			Blink();//眨眼
			count=0;
			Time=0;//计时器清零
			break;
		}
	}
}

void Forward(void)//向前
{
	delay=1000;
	
	while(1)
	{
		count++;
		delay_us(1000);
		if(count==1)
		{
			For(90,70,4);
		}
		if(count==50)
		{   
			For(90,80,3); 
		}
		if(count==100)
		{ 
			Erase_Blink();//擦除眨眼 
			Squint();//眯眼
			For(90,70,1);
			For(90,70,2);
		}
		if(count==300)
		{
			For(70,90,4);
			For(80,90,3);
		}
		if(count==350)
		{
			For(90,100,4);
		}
		if(count==400)
		{
			For(90,110,3);
		}
		if(count==450)
		{
			For(70,110,1);
			For(70,110,2);
		}
		if(count==650)
		{
			For(100,90,4);
			For(110,90,3);
		}
		if(count==700)
		{
			For(110,90,1);
			For(110,90,2);
			Time=0;//计时器清零
			count=0;
			break;
		}
	}
}

void Backward(void)//向后
{
	delay=1000;
	
	while(1)
	{
		count++;
		delay_us(1000);
		if(count==1)
		{
			For(90,70,4);
		}
		if(count==50)
		{
			For(90,80,3);
		}
		if(count==100)
		{
			Erase_Blink();//擦除眨眼 
			Squint();//眯眼
			For(90,110,1);
			For(90,110,2);
		}
		if(count==300)
		{
			For(70,90,4);
			For(80,90,3);
		}
		if(count==350)
		{
			For(90,110,3);
		}
		if(count==400)
		{
			For(90,100,4);
		}
		if(count==450)
		{
			For(110,70,1);
			For(110,70,2);
		}
		if(count==650)
		{
			For(100,90,4);
			For(110,90,3);
		}
		if(count==700)
		{
			For(70,90,1);
			For(70,90,2);
			Time=0;//计时器清零
			count=0;
			break;
		}
	}
}

void Right(void)//右转
{
	delay=1000;
	
	while(1)
	{
		count++;
		delay_us(1000);
		if(count==1)
		{
			For(90,110,3);
			For(90,100,4);
		}
		if(count==50)
		{
			Erase_Blink();//擦除眨眼 
			Ellipse_right();//椭圆向右看眼
			For(90,120,2);
		}
		if(count==200)
		{
			For(110,80,3);
			For(100,70,4);
		}
		if(count==300)
		{
			For(120,90,2);
		}
		if(count==450)
		{
			For(80,90,3);
			For(70,90,4);
		}
		if(count==500)
		{
			Time=0;//计时器清零
			count=0;
			break;
		}
	}
}

void Left(void)//左转
{
	delay=1000;
	
	while(1)
	{
		count++;
		delay_us(1000);
		if(count==1)
		{
			For(90,80,3);
			For(90,70,4);
		}
		if(count==50)
		{
			Erase_Blink();//擦除眨眼 
			Ellipse_left();//椭圆向左看眼
			For(90,60,1);
		}
		if(count==200)
		{
			For(80,110,3);
			For(70,100,4);
		}
		if(count==300)
		{
			For(60,90,1);
		}
		if(count==450)
		{
			For(110,90,3);
			For(100,90,4);
		}
		if(count==500)
		{
			Time=0;//计时器清零
			count=0;
			break;
		}
	}
}

void Shift_left(void)//左移
{
	delay=500;
	
	if(Execute_once==0)
	{
		Look_left();//斜眼向左看
	}
	Execute_once=1;
	
	Look_left();//斜眼向左看
	Servo_Control(90,1);
	Servo_Control(90,2);
	
	For(80,110,3);
	For(70,90,4);
	delay_ms(100);
		
	Time=0;//计时器清零
}

void Shift_right(void)//右移
{
	delay=500;
	
	if(Execute_once==0)
	{
		Look_right();//斜眼向右看
	}
	Execute_once=1;
	
	Servo_Control(90,1);
	Servo_Control(90,2);
	
	For(100,70,4);
	For(110,90,3);
	delay_ms(100);
	
	Time=0;//计时器清零
}

void Dance(void)//舞蹈
{
	int i = 0;
	delay=10000;
	
	Servo_Control(90,1);
	Servo_Control(90,2);
	Open_eyes();
	
	For(90,120,3);
	for(i=1;i<=30;i++)
	{
		Servo_Control(120+i,3);
		Servo_Control(90-i,4);
		delay_ms(20);
//		For(109+i,110+i,3);
//		For(91-i,90-i,4);
	}
	For(60,30,4);
	For(150,120,3);
	for(i=1;i<=30;i++)
	{
		Servo_Control(120-i,3);
		Servo_Control(30+i,4);
		delay_ms(20);
//		For(131-i,130-i,3);
//		For(29+i,30+i,4);
	}
	For(60,90,4);
	
	Erase_0pen_eyes();//擦除睁眼
	Ellipse_eyes();//椭圆眼
	delay_ms(100);
	Erase_Ellipse_eyes();//擦除椭圆眼
	Open_eyes();
/////////////////////////////////////////////////////////	///////////
	For(90,60,4);
	for(i=1;i<=30;i++)
	{
		Servo_Control(60-i,4);
		Servo_Control(90+i,3);
		delay_ms(20);
//		For(109+i,110+i,3);
//		For(91-i,90-i,4);
	}
	For(120,150,3);
	For(30,60,4);
	for(i=1;i<=30;i++)
	{
		Servo_Control(60+i,4);
		Servo_Control(150-i,3);
		delay_ms(20);
//		For(131-i,130-i,3);
//		For(29+i,30+i,4);
	}
	For(120,90,3);
////////////////////////////////////////////////////////////////////////
	for(i=1;i<=60;i++)
	{
		Servo_Control(90+i,3);
		Servo_Control(90-i,4);
		delay_ms(5);
	}
	delay_ms(500);
	for(i=1;i<=60;i++)
	{
		Servo_Control(150-i,3);
		Servo_Control(30+i,4);
		delay_ms(5);
	}
	delay_ms(500);
	for(i=1;i<=60;i++)
	{
		Servo_Control(90+i,3);
		Servo_Control(90-i,4);
		delay_ms(5);
	}
	delay_ms(500);
	for(i=1;i<=60;i++)
	{
		Servo_Control(150-i,3);
		Servo_Control(30+i,4);
		delay_ms(5);
	}
	delay_ms(500);
	/////////////////////////////////////////////////////////////////
	Servo_Control(60,3);
	delay_ms(100);
	Servo_Control(5,4);
	delay_ms(500);
	Servo_Control(90,4);
	delay_ms(200);
	
	Servo_Control(120,4);
	Erase_0pen_eyes();//擦除睁眼
	Ellipse_eyes();//椭圆眼
	delay_ms(200);
	Erase_Ellipse_eyes();//擦除椭圆眼
	Open_eyes();
	Servo_Control(90,4);
	delay_ms(200);
	Servo_Control(120,4);
	delay_ms(200);
	Servo_Control(90,4);
	delay_ms(200);
	for(i=1;i<=30;i++)
	{
		Servo_Control(60+i,3);
		delay_ms(10);
	}
	delay_ms(1000);
	
	Servo_Control(120,4);
	delay_ms(100);
	Servo_Control(185,3);
	delay_ms(500);
	Servo_Control(90,3);
	delay_ms(200);
	
	Servo_Control(60,3);
	delay_ms(200);
	Servo_Control(90,3);
	delay_ms(200);
	Servo_Control(60,3);
	delay_ms(200);
	Servo_Control(90,3);
	delay_ms(200);
	for(i=1;i<=30;i++)
	{
		Servo_Control(120-i,4);
		delay_ms(10);
	}
	delay_ms(100);
	/////////////////////////////////////////////////////////////////////////
	for(i=1;i<=60;i++)
	{
		Servo_Control(90-i,3);
		Servo_Control(90+i,4);
		delay_ms(5);
	}
	delay_ms(500);
	for(i=1;i<=60;i++)
	{
		Servo_Control(30+i,3);
		Servo_Control(150-i,4);
		delay_ms(5);
	}
	delay_ms(500);
	for(i=1;i<=60;i++)
	{
		Servo_Control(90-i,3);
		Servo_Control(90+i,4);
		delay_ms(5);
	}
	delay_ms(500);
	for(i=1;i<=60;i++)
	{
		Servo_Control(30+i,3);
		Servo_Control(150-i,4);
		delay_ms(5);
	}
	
	delay_ms(500);
	//////////////////////////////////////////////////////////////////
	Erase_0pen_eyes();//擦除睁眼
	Blink();//眨眼
	delay_ms(100);
	Erase_Blink();//擦除眨眼
	Open_eyes();//睁眼
}

void Shake_hands(void)//摇手
{
	u8 i = 0;
	
	if(Execute_once >= 20)i = 1;
	
	if(Execute_once == 0 && i == 0)
	{
		Cute_squint();
		Servo_Control(90,1);
		Servo_Control(90,2);
		Servo_Control(90,3);
		Servo_Control(90,4);
		delay_ms(100);
		Servo_Control(55,3);
		delay_ms(100);
		Servo_Control(5,4);
		delay_ms(500);
		Servo_Control(90,4);
		delay_ms(200);
	}
	if(Execute_once == 20 && i == 1)
	{
		Cute_squint();
		Servo_Control(90,1);
		Servo_Control(90,2);
		Servo_Control(90,3);
		delay_ms(100);
		Servo_Control(125,4);
		delay_ms(100);
		Servo_Control(185,3);
		delay_ms(500);
		Servo_Control(90,3);
		delay_ms(200);
	}
	
	if(i == 0)
	{
		Servo_Control(120,4);
		delay_ms(200);
		Servo_Control(80,4);
		delay_ms(200);
	}
	if(i == 1)
	{
		Servo_Control(60,3);
		delay_ms(200);
		Servo_Control(100,3);
		delay_ms(200);
	}
	
	Execute_once++;
	Time=0;//计时器清零
}



void Idle_task(void)//空闲任务
{
	if(Time==1)
	{
		OLED_Clear();
		Blink();//眨眼
		Servo_Control(90,1);
		Servo_Control(90,2);
		Servo_Control(90,3);
		Servo_Control(90,4);
		delay_ms(200);
		Erase_Blink();//擦除眨眼
		Open_eyes();//睁眼
	}
	if(Time==8)
	{
		Erase_0pen_eyes();//擦除睁眼
		Half_blink();//半眨眼
		delay_ms(200);
		Erase_Half_blink();//擦除半眨眼
		Open_eyes();//睁眼
	}
	if(Time==10)
	{
		Erase_0pen_eyes();//擦除睁眼
		Half_blink();//半眨眼
		delay_ms(200);
		Erase_Half_blink();//擦除半眨眼
		Open_eyes();//睁眼
	}
	if(Time==13)
	{
		Erase_0pen_eyes();//擦除睁眼
		Blink();//眨眼
		delay_ms(200);
		Erase_Blink();//擦除眨眼
		Look_left();//斜眼向左看
	}
	if(Time==17)
	{
		Erase_Look_left();//擦除向左看
		Blink();
		delay_ms(200);
		Erase_Blink();//擦除眨眼
		Look_right();//斜眼向右看
	}
	if(Time==21)
	{
		Erase_Look_right();//擦除向右看
		Blink();
		delay_ms(200);
		Erase_Blink();//擦除眨眼
		Query_left();//疑问向左看眼
	}
	if(Time==25)
	{
		Erase_Query_left();//擦除疑问向右看眼
		Blink();
		delay_ms(200);
		Erase_Blink();//擦除眨眼
		Sleep1();
	}
	if(Time>=26&&Time%2==0&&Time<200)
	{
		Sleep2();
	}
	if(Time>=26&&Time%2!=0&&Time<200)
	{
		Sleep1();
	}
	if(Time>200)
	{
		Erase_Sleep();//擦除睡觉
		Blink();
		Time=0;//计时器清零
	}	
}
