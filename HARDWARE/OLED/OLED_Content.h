#ifndef __OLED_CONTENT_H
#define __OLED_CONTENT_H	 
#include "sys.h"
#include "oled.h"              //OLED显示屏
#include "OLED_Data.h"         //OLED数据
#include "OLED_Content.h"      //OLED内容
#include "adc.h"
#include "mode.h"


void Open_eyes(void);//睁眼
void Erase_0pen_eyes(void);//擦除睁眼


void Half_blink(void);//半眨眼
void Erase_Half_blink(void);//擦除半眨眼


void Blink(void);//眨眼
void Erase_Blink(void);//擦除眨眼


void Look_left(void);//斜眼向左看
void Erase_Look_left(void);//擦除向左看


void Look_right(void);//斜眼向右看
void Erase_Look_right(void);//擦除向右看


void love(void);//爱心眼
void Erase_love(void);//擦除爱心眼


void love_min(void);//小爱心眼
void Erase_love_min(void);//擦除小爱心眼

void XX_eyes(void);//XX眼
void Erase_XX_eyes(void);//擦除XX眼


void Ellipse_eyes(void);//椭圆眼
void Erase_Ellipse_eyes(void);//擦除椭圆眼


void Ellipse_right(void);//椭圆向右看眼
void Erase_Ellipse_right(void);//擦除椭圆向右看眼


void Ellipse_left(void);//椭圆向左看眼
void Erase_Ellipse_left(void);//擦除椭圆向右看眼


void Query_right(void);//疑问向右看眼
void Erase_Query_right(void);//擦除疑问向右看眼


void Query_left(void);//疑问向左看眼
void Erase_Query_left(void);//擦除疑问向右看眼
	

void Squint(void);//眯眼
void Erase_Squint(void);//擦除眯眼


void Smile(void);//笑脸
void Erase_Smile(void);//擦除笑脸

void Sleep1(void);//睡觉
void Sleep2(void);//睡觉
void Erase_Sleep(void);//擦除睡觉

void Cute_squint(void);//可爱眯眼
void Erase_Cute_squint(void);//擦除可爱眯眼

void OLED_Electricity(void);//显示当前电量
void Vol_warn(void);//电量提醒
		 				    
#endif
