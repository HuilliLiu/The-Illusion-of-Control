#ifndef __SERVO_H
#define __SERVO_H	 

#include "sys.h"
#include "delay.h"
#include "flash.h"
#include "mode.h"

extern int Servo_Voice;
extern int Servo_Sign;
extern u16 delay;

void Servo_Control(float angle ,int num);
void Servo_Amend(void);//¶æ»ú½Ç¶ÈÐÞÕý
void TIM2_Init(u16 arr,u16 psc);
void TIM3_Init(u16 arr,u16 psc);
void For(int x,int y,int num);

#endif
