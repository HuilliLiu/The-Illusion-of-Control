#include "flash.h"


u16 Store_Data[512];


u32 MyFLASH_ReadWord(u32 Address)//读字
{
	return *((__IO u32 *)(Address));
}

u16 MyFLASH_ReadHalfWord(u16 Address)//读半字
{
	return *((__IO u16 *)(Address));
}

u8 MyFLASH_ReadByte(u8 Address)//读字节
{
	return *((__IO u8 *)(Address));
}



void MyFLASH_EraseAllPages(void)//全擦除
{
	FLASH_Unlock();
	FLASH_EraseAllPages();
	FLASH_Lock();
}

void MyFLASH_ErasePages(u32 Address)//页擦除
{
	FLASH_Unlock();
	FLASH_ErasePage(Address);
	FLASH_Lock();
}


void MyFLASH_ProgramWord(u32 Address , u32 data)//写入字
{
	FLASH_Unlock();
	FLASH_ProgramWord(Address,data);
	FLASH_Lock();
}

void MyFLASH_ProgramHalfWord(u32 Address , u16 data)//写入半字
{
	FLASH_Unlock();
	FLASH_ProgramHalfWord(Address,data);
	FLASH_Lock();
}


//c8t6最后一页为0x0800FC00
//c6t6最后一页为0x08007C00

void Store_Init(void)//初始化flash 0x08007C00页
{
	u16 i;
	
	if(MyFLASH_ReadHalfWord(0x0800FC00) != 0xA5A5)//如果数据仓库第一个半字不是A5A5,说明不是第一次使用
	{
		MyFLASH_ErasePages(0x0800FC00);//擦除整页
		MyFLASH_ProgramHalfWord(0x0800FC00,0xA5A5);//据仓库第一个半字写入A5A5
		for(i=1 ; i<512 ; i++)
		{
			MyFLASH_ProgramHalfWord(0x0800FC00+i*2,0x0000);
		}
	}
	for(i=0 ; i<512 ; i++)
	{
		Store_Data[i] = MyFLASH_ReadHalfWord(0x0800FC00+i*2);//把页数据读到数据仓库
	}
}


void Store_Save(void)//数据存储
{
	u16 i;
	
	MyFLASH_ErasePages(0x0800FC00);//擦除整页
	for(i=0 ; i<512 ; i++)
	{
		MyFLASH_ProgramHalfWord(0x0800FC00+i*2,Store_Data[i]);//把数据仓库的数据备份到Flash
	}
}

void Store_Clear(void)//数据仓库数据清零
{
	u16 i;
	
	for(i=1 ; i<512 ; i++)
	{
		Store_Data[i] = 0x0000;
	}
	Store_Save();//存储数据
}