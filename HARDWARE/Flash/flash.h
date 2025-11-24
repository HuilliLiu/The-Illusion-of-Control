#ifndef __FLASH_H
#define __FLASH_H	 
#include "sys.h"
	 		
extern u16 Store_Data[];


u32 MyFLASH_ReadWord(u32 Address);//读字
u16 MyFLASH_ReadHalfWord(u16 Address);//读半字
u8 MyFLASH_ReadByte(u8 Address);//读字节

void MyFLASH_EraseAllPages(void);//全擦除
void MyFLASH_ErasePages(u32 Address);//页擦除

void MyFLASH_ProgramWord(u32 Address , u32 data);//写入字
void MyFLASH_ProgramHalfWord(u32 Address , u16 data);//写入半字


void Store_Init(void);//初始化flash 0x08007C00页
void Store_Save(void);//数据存储
void Store_Clear(void);//数据仓库数据清零

#endif
