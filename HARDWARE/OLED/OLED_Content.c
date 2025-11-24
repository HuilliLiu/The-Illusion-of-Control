#include "OLED_Content.h"



void Open_eyes(void)//ÕöÑÛ
{
	OLED_ShowImage(14,12,40,40,eyeA);
	OLED_ShowImage(74,12,40,40,eyeA);
	OLED_Update();
}
void Erase_0pen_eyes(void)//²Á³ýÕöÑÛ
{
	OLED_ClearArea(14,12,40,40);
	OLED_ClearArea(74,12,40,40);
	OLED_Update();
}


void Half_blink(void)//°ëÕ£ÑÛ
{
	OLED_ShowImage(14,12,40,40,eyeD);
	OLED_ShowImage(74,12,40,40,eyeD);
	OLED_Update();
}
void Erase_Half_blink(void)//²Á³ý°ëÕ£ÑÛ
{
	OLED_ClearArea(14,12,40,40);
	OLED_ClearArea(74,12,40,40);
	OLED_Update();
}


void Blink(void)//Õ£ÑÛ
{
	OLED_ShowImage(14,12,48,48,eyea);
	OLED_ShowImage(74,12,48,48,eyea);
	OLED_Update();
}
void Erase_Blink(void)//²Á³ýÕ£ÑÛ
{
	OLED_ClearArea(14,12,48,48);
	OLED_ClearArea(74,12,48,48);
	OLED_Update();
}


void Look_left(void)//Ïò×ó¿´
{
	OLED_ShowImage(14,10,40,40,eyeC);
	OLED_ShowImage(74,14,40,40,eyeC);
	OLED_Update();
}
void Erase_Look_left(void)//²Á³ýÏò×ó¿´
{
	OLED_ClearArea(14,10,40,40);
	OLED_ClearArea(74,14,40,40);
	OLED_Update();
}


void Look_right(void)//ÏòÓÒ¿´
{
	OLED_ShowImage(14,14,40,40,eyeB);
	OLED_ShowImage(74,10,40,40,eyeB);
	OLED_Update();
}
void Erase_Look_right(void)//²Á³ýÏòÓÒ¿´
{
	OLED_ClearArea(14,14,40,40);
	OLED_ClearArea(74,10,40,40);
	OLED_Update();
}


void love(void)//°®ÐÄÑÛ
{
	OLED_ShowImage(5,10,54,48,eyeb);//54,48
	OLED_ShowImage(69,10,54,48,eyeb);
	OLED_Update();
}
void Erase_love(void)//²Á³ý°®ÐÄÑÛ
{
	OLED_ClearArea(5,10,54,48);
	OLED_ClearArea(69,10,54,48);
	OLED_Update();
}


void love_min(void)//Ð¡°®ÐÄÑÛ
{
	OLED_ShowImage(14,12,41,40,eyeE);
	OLED_ShowImage(74,12,41,40,eyeE);
	OLED_Update();
}
void Erase_love_min(void)//²Á³ýÐ¡°®ÐÄÑÛ
{
	OLED_ClearArea(14,12,41,40);
	OLED_ClearArea(74,12,41,40);
	OLED_Update();
}


void XX_eyes(void)//XXÑÛ
{
	OLED_ShowImage(14,12,40,40,eyeF);
	OLED_ShowImage(74,12,40,40,eyeF);
	OLED_Update();
}
void Erase_XX_eyes(void)//²Á³ýXXÑÛ
{
	OLED_ClearArea(14,12,40,40);
	OLED_ClearArea(74,12,40,40);
	OLED_Update();
}


void Ellipse_eyes(void)//ÍÖÔ²ÑÛ
{
	OLED_ShowImage(14,12,40,40,eyeG);
	OLED_ShowImage(74,12,40,40,eyeG);
	OLED_Update();
}
void Erase_Ellipse_eyes(void)//²Á³ýÍÖÔ²ÑÛ
{
	OLED_ClearArea(14,12,40,40);
	OLED_ClearArea(74,12,40,40);
	OLED_Update();
}


void Ellipse_right(void)//ÍÖÔ²ÏòÓÒ¿´ÑÛ
{
	OLED_ShowImage(18,12,40,40,eyeH);
	OLED_ShowImage(80,12,40,40,eyeI);
	OLED_Update();
}
void Erase_Ellipse_right(void)//²Á³ýÍÖÔ²ÏòÓÒ¿´ÑÛ
{
	OLED_ClearArea(18,12,40,40);
	OLED_ClearArea(80,12,40,40);
	OLED_Update();
}


void Ellipse_left(void)//ÍÖÔ²Ïò×ó¿´ÑÛ
{
	OLED_ShowImage(8,12,40,40,eyeK);
	OLED_ShowImage(70,12,40,40,eyeJ);
	OLED_Update();
}
void Erase_Ellipse_left(void)//²Á³ýÍÖÔ²ÏòÓÒ¿´ÑÛ
{
	OLED_ClearArea(8,12,40,40);
	OLED_ClearArea(70,12,40,40);
	OLED_Update();
}


void Query_right(void)//ÒÉÎÊÏòÓÒ¿´ÑÛ
{
	OLED_ShowImage(3,1,20,20,Query1);
	OLED_ShowImage(18,18,40,40,eyeH);
	OLED_ShowImage(80,18,40,40,eyeI);
	OLED_Update();
}
void Erase_Query_right(void)//²Á³ýÒÉÎÊÏòÓÒ¿´ÑÛ
{
	OLED_ClearArea(3,1,20,20);
	OLED_ClearArea(18,18,40,40);
	OLED_ClearArea(80,18,40,40);
	OLED_Update();
}


void Query_left(void)//ÒÉÎÊÏò×ó¿´ÑÛ
{
	OLED_ShowImage(110,1,20,20,Query2);
	OLED_ShowImage(8,16,40,40,eyeK);
	OLED_ShowImage(70,16,40,40,eyeJ);
	OLED_Update();
}
void Erase_Query_left(void)//²Á³ýÒÉÎÊÏòÓÒ¿´ÑÛ
{
	OLED_ClearArea(110,1,20,20);
	OLED_ClearArea(8,16,40,40);
	OLED_ClearArea(70,16,40,40);
	OLED_Update();
}



void Squint(void)//ÃÐÑÛ
{
//	OLED_ShowImage(14,12,40,40,eyeL);
//	OLED_ShowImage(74,12,40,40,eyeM);
	OLED_ShowImage(0,0,128,64,squint);
	OLED_Update();
}
void Erase_Squint(void)//²Á³ýÃÐÑÛ
{
	OLED_Clear();
//	OLED_ClearArea(14,12,40,40);
//	OLED_ClearArea(74,12,40,40);
//	OLED_Update();
}


void Smile(void)//Ð¦Á³
{
	OLED_ShowImage(14,12,40,40,eyeN);
	OLED_ShowImage(74,12,40,40,eyeN);
	OLED_Update();
}
void Erase_Smile(void)//²Á³ýÐ¦Á³
{
	OLED_ClearArea(14,12,40,40);
	OLED_ClearArea(74,12,40,40);
	OLED_Update();
}


void Sleep1(void)//Ë¯¾õ
{
	OLED_ShowImage(0,0,128,64,sleep1);
	OLED_Update();
}
void Sleep2(void)//Ë¯¾õ
{
	OLED_ShowImage(0,0,128,64,sleep2);
	OLED_Update();
}
void Erase_Sleep(void)//²Á³ýË¯¾õ
{
	OLED_Clear();
}

void Cute_squint(void)//¿É°®ÃÐÑÛ
{
	OLED_ShowImage(0,0,128,64,cute_squint);
	OLED_Update();
}
void Erase_Cute_squint(void)//²Á³ý¿É°®ÃÐÑÛ
{
	OLED_Clear();
}

void OLED_Electricity(void)//ÏÔÊ¾µ±Ç°µçÁ¿
{
	//OLEDÏÔÊ¾Êý¾Ý
	u8 string[10]={0};
	u16 value=0;//adÖµ
	float vol;//µçÑ¹Öµ
	
	value=Get_ADC_Value(ADC_Channel_4,20);
	vol=(float)value*(3.3/4096);
	vol=(vol*3)+0.17;
	
	OLED_Clear();
	sprintf((char *)string,"%.2f",vol);
	OLED_ShowString(80,4,string,6);
	OLED_Update();
	
	if(vol>=7.8)
	{
		usart2_send((uint8_t*)"ee",2);
		OLED_ShowImage(112,0,15,15,Cell3);
		OLED_Update();
	}
	else if(vol>=7.5&&vol<7.8)
	{
		usart2_send((uint8_t*)"ff",2);
		OLED_ShowImage(112,0,15,15,Cell2);
		OLED_Update();
	}
	else if(vol>=7.2&&vol<7.5)
	{
		usart2_send((uint8_t*)"gg",2);
		OLED_ShowImage(112,0,15,15,Cell1);
		OLED_Update();
	}
	else
	{
		usart2_send((uint8_t*)"hh",2);
		OLED_ShowImage(112,0,15,15,Cell0);
		OLED_Update();
	}
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	Sign=1;
	Time=0;
	OLED_Clear();
}

void Vol_warn(void)//µçÁ¿ÌáÐÑ
{
	float vol;//µçÑ¹Öµ
	u16 value=0;//adÖµ
	
	value=Get_ADC_Value(ADC_Channel_4,20);
	vol=(float)value*(3.3/4096);
	vol=(vol*3)+0.17;

	if(vol>=6.85&&vol<=6.88)
	{
		usart2_send((uint8_t*)"hh",2);
	}
	
}