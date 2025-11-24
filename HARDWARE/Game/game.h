#ifndef __GAME_H
#define __GAME_H	 

#include "sys.h"
#include "tianwen.h"
#include "OLED.h"
#include <stdio.h>
#include <stdlib.h>
#include "OLED_Content.h"
#include "OLED_Data.h"

//全局变量
#define ROW 3    //行
#define COL 3    //列

extern int Chess_Voice;//位置
extern int Voice; //判断是否接收到位置信息


void Game_Init(int board[ROW][COL], int row, int col);//初始化棋盘
void OLED_chess(int x,int y,char A);//显示棋子
void playerA(int board[ROW][COL], int row, int col);//玩家下棋
void playerB(int board[ROW][COL], int row, int col);//随机算法
int attack(int board[ROW][COL], int row, int col);//电脑进攻算法 q=0随机下 q=1进攻
int defense(int board[ROW][COL], int row, int col);//电脑防守算法
int IsFull(int board[ROW][COL], int row, int col);//判断棋盘是否排满
int judge(int board[ROW][COL], int row, int col);//判断输赢
void Game(void);//游戏入口

void usart2_send(unsigned char *data,unsigned char len);//串口发送字符串

		 				    
#endif
