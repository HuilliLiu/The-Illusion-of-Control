#ifndef __OLED_DATA_H
#define __OLED_DATA_H

#include <stdint.h>

/*中文字符字节宽度*/
#define OLED_CHN_CHAR_WIDTH			2		//UTF-8编码格式给3，GB2312编码格式给2

/*字模基本单元*/
typedef struct 
{
	char Index[OLED_CHN_CHAR_WIDTH + 1];	//汉字索引
	uint8_t Data[32];						//字模数据
} ChineseCell_t;

/*ASCII字模数据声明*/
extern const uint8_t OLED_F8x16[][16];
extern const uint8_t OLED_F6x8[][6];

/*汉字字模数据声明*/
extern const ChineseCell_t OLED_CF16x16[];

/*图像数据声明*/
extern const uint8_t Diode[];//二极管
extern const uint8_t Cell0[];//电池0
extern const uint8_t Cell1[];//电池1
extern const uint8_t Cell2[];//电池2
extern const uint8_t Cell3[];//电池3

/*宽16像素，高16像素*/
extern const uint8_t PlayA[];//玩家
extern const uint8_t PlayB[];//电脑

/*宽20像素，高20像素*/
extern const uint8_t Query1[];//左疑问
extern const uint8_t Query2[];//右疑问

/*宽30像素，高30像素*/
extern const uint8_t eye1[];//睁眼

/*宽40像素，高40像素*/
extern const uint8_t eyeA[];//睁眼
extern const uint8_t eyeB[];//向左斜眼
extern const uint8_t eyeC[];//向右斜眼
extern const uint8_t eyeD[];//半眨眼
extern const uint8_t eyeE[];//小爱心41，40
extern const uint8_t eyeF[];//XX
extern const uint8_t eyeG[];//椭圆眼
extern const uint8_t eyeH[];//椭圆向右看小眼
extern const uint8_t eyeI[];//椭圆向右看大眼
extern const uint8_t eyeJ[];//椭圆向左看小眼
extern const uint8_t eyeK[];//椭圆向左看大眼
extern const uint8_t eyeL[];//眯眼左
extern const uint8_t eyeM[];//眯眼右
extern const uint8_t eyeN[];//弯眼

/*宽48像素，高48像素*/
extern const uint8_t eyea[];//眨眼

/*宽54像素，高48像素*/
extern const uint8_t eyeb[];//爱心

/*宽64像素，高64像素*/
extern const uint8_t Chessboard[];//棋盘

/*宽128像素，高64像素*/
extern const uint8_t sleep1[];//睡觉
extern const uint8_t sleep2[];//睡觉
extern const uint8_t squint[];//眯眼
extern const uint8_t cute_squint[];//可爱眯眼

/*按照上面的格式，在这个位置加入新的图像数据声明*/
//...

#endif

