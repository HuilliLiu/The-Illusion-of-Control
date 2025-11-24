#include "Servo.h"

/*
         ---------------
        |     O   O     |
        |---------------|
PA1==> |               | <== PA0
         ---------------
            ||     ||
            ||     ||
PB0==>   -----   ------  <== PA7
         |-----   ------|
				 
PA1是一号舵机
PA0是二号舵机
PB0是三号舵机
PA7是四号舵机

*/
int Servo_Voice=0;//用于判断上下一次的语音指令是否改变
int Servo_Sign=0;//接收舵机改变值的语音指令
u16 pwmval=0;//角度转换
u16 delay=1000;//每度延时时间


void TIM2_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//使能定时器2时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIO外设时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1; //TIM2_CH1  TIM2_CH2  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIO
 
   //初始化TIM2
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	//初始化TIM2 Channel-4 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM2 OC1
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM2在CCR1上的预装载寄存器
	
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM2 OC2
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM2在CCR1上的预装载寄存器
 
	TIM_Cmd(TIM2, ENABLE);  //使能TIM2
	
}

void TIM3_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//使能定时器3时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);  //使能GPIO外设时钟

	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; // TIM3_CH2  
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIO

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // TIM3_CH4  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIO
 
   //初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	//初始化TIM2 Channel-4 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC2
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM2在CCR1上的预装载寄存器

	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC3
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM2在CCR1上的预装载寄存器
 
	TIM_Cmd(TIM3, ENABLE);  //使能TIM3
	
}


void Servo_Amend(void)//舵机角度修正
{
	while(1)
	{
		Servo_Control(90,1);
		Servo_Control(90,2);
		Servo_Control(90,3);
		Servo_Control(90,4);
		OLED_Clear();
		Open_eyes();//睁眼
		
		if(Servo_Sign==2)
		{
			Store_Data[2]+=2;
			Servo_Sign=0;
			Servo_Voice=0;//接收标致清零
		}
		if(Servo_Sign==3)
		{
			Store_Data[2]-=2;
			Servo_Sign=0;
			Servo_Voice=0;
		}
		if(Servo_Sign==4)
		{
			Store_Data[3]+=2;
			Servo_Sign=0;
			Servo_Voice=0;
		}
		if(Servo_Sign==5)
		{
			Store_Data[3]-=2;
			Servo_Sign=0;
			Servo_Voice=0;
		}
		if(Servo_Sign==6)
		{
			Store_Data[4]+=2;
			Servo_Sign=0;
			Servo_Voice=0;
		}
		if(Servo_Sign==7)
		{
			Store_Data[4]-=2;
			Servo_Sign=0;
			Servo_Voice=0;
		}
		if(Servo_Sign==8)
		{
			Store_Data[5]+=2;
			Servo_Sign=0;
			Servo_Voice=0;
		}
		if(Servo_Sign==9)
		{
			Store_Data[5]-=2;
			Servo_Sign=0;
			Servo_Voice=0;
		}
		if(Servo_Sign==10)
		{
			Store_Data[0]=0xA5A5;
			Store_Save();//存储数据到flash
			Sign=1;
			Erase_0pen_eyes();//擦除睁眼
			break;
		}
	}
}


//舵机角度精确控制函数

void Servo_Control(float angle ,int num)//angle 转动角度  num 几号舵机
{
	pwmval=0;
	
	if(num==1)
	{
		pwmval = (int)(2000*(1-((0.5+angle/90.0)/20.0)))+Store_Data[2];
		TIM_SetCompare2(TIM2, pwmval);
	}
	else if(num==2)
	{
		pwmval = (int)(2000*(1-((0.5+angle/90.0)/20.0)))+Store_Data[3];
		TIM_SetCompare1(TIM2, pwmval);
	}
	else if(num==3)
	{
		pwmval = (int)(2000*(1-((0.5+angle/90.0)/20.0)))+Store_Data[4];
		TIM_SetCompare3(TIM3, pwmval);
	}
	else if(num==4)
	{
		pwmval = (int)(2000*(1-((0.5+angle/90.0)/20.0)))+Store_Data[5];
		TIM_SetCompare2(TIM3, pwmval);
	}
//假设我们需要舵机旋转45°，则占空比为1ms/20ms=5%，则TIM_SetCompare2TIMx 捕获比较 1 寄存器值就是2000-2000*5%=1900；
//占空比从0.5开始为0°，因此需要以0.5开始相加，我们假设把45°为angle带进去，则最里面的括号为1，正好对标舵机45°时候的1ms。
//最后面的数组值是调整舵机误差。
}

/**
  * 函    数：动作延时函数
  * 参    数：x是初始角度，y是要到达的角度，num是舵机号
  * 返 回 值：无
  */
void For(int x,int y,int num)
{
	int i;//记录角度
	
	if(num==1)
	{
		if(x>=y)
		{
			for(i=x;i>=y;i--)
			{
				Servo_Control(i,num);
				delay_us(delay);
			}
		}
		else
		{
			for(i=x;i<=y;i++)
			{
				Servo_Control(i,num);
				delay_us(delay);
			}
		}
	}
	
	if(num==2)
	{
		if(x>=y)
		{
			for(i=x;i>=y;i--)
			{
				Servo_Control(i,num);
				delay_us(delay);
			}
		}
		else
		{
			for(i=x;i<=y;i++)
			{
				Servo_Control(i,num);
				delay_us(delay);
			}
		}
	}
	
	if(num==3)
	{
		if(x>=y)
		{
			for(i=x;i>=y;i--)
			{
				Servo_Control(i,num);
				delay_us(delay);
			}
		}
		else
		{
			for(i=x;i<=y;i++)
			{
				Servo_Control(i,num);
				delay_us(delay);
			}
		}
	}
	
	if(num==4)
	{
		if(x>=y)
		{
			for(i=x;i>=y;i--)
			{
				Servo_Control(i,num);
				delay_us(delay);
			}
		}
		else
		{
			for(i=x;i<=y;i++)
			{
				Servo_Control(i,num);
				delay_us(delay);
			}
		}
	}
}
