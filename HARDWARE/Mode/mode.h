#ifndef __MODE_H
#define __MODE_H	 

#include "sys.h"
#include "Servo.h"
#include "led.h"
#include "tianwen.h"
#include "delay.h"
#include "OLED.h"
#include "OLED_Content.h"
#include "OLED_Data.h"

extern u16 Time;
extern int Sign;
extern int Sign_records;
extern int Execute_once;
extern u8 i;

void TIM1_Init(void);//任务计时
void Shake_leg(void);//抖腿
void Forward(void);
void Backward(void);
void Right(void);
void Left(void);
void Shift_left(void);
void Shift_right(void);
void Dance(void);//舞蹈
void Shake_hands(void);//摇手
void Idle_task(void);//空闲任务
		 				    
#endif
