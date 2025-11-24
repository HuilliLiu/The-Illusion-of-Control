#include "game.h"

int Chess_Voice=0;//位置
int Voice =0; //判断是否接收到位置信息
int ret = 0;//判断输赢
//玩家执O棋
//电脑执X棋



void Game_Init(int board[ROW][COL], int row, int col)//初始化棋盘
{
	int i=0,j=0;
	
	OLED_Clear();//清屏
	OLED_ShowImage(33,0,64,64,Chessboard);//画棋盘
	OLED_ShowNum(41,3,'3',1,8);
	OLED_ShowNum(62,3,'4',1,8);
	OLED_ShowNum(83,3,'5',1,8);
	OLED_ShowNum(41,24,'6',1,8);
	OLED_ShowNum(62,24,'7',1,8);
	OLED_ShowNum(83,24,'8',1,8);
	OLED_ShowNum(41,45,'9',1,8);
	OLED_ShowNum(62,45,'0',1,8);
	OLED_ShowNum(83,45,'1',1,8);
	OLED_Update();

	Chess_Voice=0;
	ret = 0;
}


void OLED_chess(int x,int y,char A)//显示棋子
{
	if(A=='A')
	{
		if(x==1&&y==1)OLED_ShowImage(36,3,16,16,PlayA);//1号位
		if(x==1&&y==2)OLED_ShowImage(57,3,16,16,PlayA);//2号位
		if(x==1&&y==3)OLED_ShowImage(78,3,16,16,PlayA);//3号位
		if(x==2&&y==1)OLED_ShowImage(36,24,16,16,PlayA);//4号位
		if(x==2&&y==2)OLED_ShowImage(57,24,16,16,PlayA);//5号位
		if(x==2&&y==3)OLED_ShowImage(78,24,16,16,PlayA);//6号位
		if(x==3&&y==1)OLED_ShowImage(36,45,16,16,PlayA);//7号位
		if(x==3&&y==2)OLED_ShowImage(57,45,16,16,PlayA);//8号位
		if(x==3&&y==3)OLED_ShowImage(78,45,16,16,PlayA);//9号位
	}
	else if(A=='B')
	{
		if(x==1&&y==1)OLED_ShowImage(36,3,16,16,PlayB);//1号位
		if(x==1&&y==2)OLED_ShowImage(57,3,16,16,PlayB);//2号位
		if(x==1&&y==3)OLED_ShowImage(78,3,16,16,PlayB);//3号位
		if(x==2&&y==1)OLED_ShowImage(36,24,16,16,PlayB);//4号位
		if(x==2&&y==2)OLED_ShowImage(57,24,16,16,PlayB);//5号位
		if(x==2&&y==3)OLED_ShowImage(78,24,16,16,PlayB);//6号位
		if(x==3&&y==1)OLED_ShowImage(36,45,16,16,PlayB);//7号位
		if(x==3&&y==2)OLED_ShowImage(57,45,16,16,PlayB);//8号位
		if(x==3&&y==3)OLED_ShowImage(78,45,16,16,PlayB);//9号位
	}
	OLED_Update();
}


void playerA(int board[ROW][COL], int row, int col)//玩家下棋
{
    int x = 0;
    int y = 0;
    while (1)
    {
        if(Voice==1)//等待玩家指令
				{
						if(Chess_Voice==1)x=1,y=1;//1号位
						if(Chess_Voice==2)x=1,y=2;//2号位
						if(Chess_Voice==3)x=1,y=3;//3号位
						if(Chess_Voice==4)x=2,y=1;//4号位
						if(Chess_Voice==5)x=2,y=2;//5号位
						if(Chess_Voice==6)x=2,y=3;//6号位
						if(Chess_Voice==7)x=3,y=1;//7号位
						if(Chess_Voice==8)x=3,y=2;//8号位
						if(Chess_Voice==9)x=3,y=3;//9号位
						
						if (x > 0 && x <= row && y > 0 && y <= col)
						{
								if (board[x - 1][y - 1] == 0)
								{
										board[x - 1][y - 1] = 1;
									
										OLED_chess(x,y,'A');//显示棋子
										
										Voice=0;
									
										break;
								}
								else
								{
									usart2_send((uint8_t*)"aa",2);
									Voice=0;
								}
						}
				}
    }
}

void playerB(int board[ROW][COL], int row, int col)//随机算法
{
    int x = 0;
    int y = 0;
		
    while (1)
    {
			
        x = rand() % row;
        y = rand() % col;

	
        if (board[x][y] == 0)
        {
            board[x][y] = 2;
						
						OLED_chess(x+1,y+1,'B');//显示棋子
					
            break;
        }
    }
}


int attack(int board[ROW][COL], int row, int col)//电脑进攻函数 q=0随机下 q=1进攻
{
    int q = 0;
    int i = 0;
    //判断行是否有机会
    for (i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == 2 && board[i][2] == 0)
        {
            board[i][2] = 2;
						OLED_chess(i+1,3,'B');//显示棋子
            q = 1;
            return q;
        }
        if (board[i][0] == board[i][2] && board[i][0] == 2 && board[i][1] ==0)
        {
            board[i][1] = 2;
						OLED_chess(i+1,2,'B');//显示棋子
            q = 1;
            return q;
        }
        if (board[i][1] == board[i][2] && board[i][1] == 2 && board[i][0] == 0)
        {
            board[i][0] = 2;
						OLED_chess(i+1,1,'B');//显示棋子
            q = 1;
            return q;
        }
    }
    //判断列是否有机会
    for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == 2 && board[2][i] ==0)
        {
            board[2][i] = 2;
						OLED_chess(3,i+1,'B');//显示棋子
            q = 1;
            return q;
        }
        if (board[0][i] == board[2][i] && board[0][i] ==2 && board[1][i] == 0)
        {
            board[1][i] = 2;
						OLED_chess(2,i+1,'B');//显示棋子
            q = 1;
            return q;
        }
        if (board[1][i] == board[2][i] && board[1][i] == 2 && board[0][i] == 0)
        {
            board[0][i] = 2;
						OLED_chess(1,i+1,'B');//显示棋子
            q = 1;
            return q;
        }
    }
    //判断正对角线是否有机会
    if (board[0][0] == board[1][1] && board[0][0] == 2 && board[2][2] == 0)
    {
        board[2][2] = 2;
				OLED_chess(3,3,'B');//显示棋子
        q = 1;
        return q;
    }
    if (board[0][0] == board[2][2] && board[0][0] == 2 && board[1][1] == 0)
    {
        board[1][1] = 2;
				OLED_chess(2,2,'B');//显示棋子
        q = 1;
        return q;
    }
    if (board[2][2] == board[1][1] && board[2][2] == 2 && board[0][0] == 0)
    {
        board[0][0] = 2;
				OLED_chess(1,1,'B');//显示棋子
        q = 1;
        return q;
    }
    //判断反对角线是否有机会
    if (board[0][2] == board[1][1] && board[0][2] == 2 && board[2][0] == 0)
    {
        board[2][0] = 2;
				OLED_chess(3,1,'B');//显示棋子
        q = 1;
        return q;
    }
    if (board[0][2] == board[2][0] && board[0][2] == 2 && board[1][1] == 0)
    {
        board[1][1] = 2;
				OLED_chess(2,2,'B');//显示棋子
        q = 1;
        return q;
    }
    if (board[2][0] == board[1][1] && board[2][0] == 2 && board[0][2] == 0)
    {
        board[0][2] = 2;
				OLED_chess(1,3,'B');//显示棋子
        q = 1;
        return q;
    }
    return q;            //不需要进攻
}



int defense(int board[ROW][COL], int row, int col)//电脑防守函数
{
    int q = 0;
    int i = 0;
    //判断行是否有机会
    for (i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == 1 && board[i][2] == 0)
        {
            board[i][2] = 2;
						OLED_chess(i+1,3,'B');//显示棋子
            q = 1;
            return q;
        }
        if (board[i][0] == board[i][2] && board[i][0] == 1 && board[i][1] == 0)
        {
            board[i][1] = 2;
						OLED_chess(i+1,2,'B');//显示棋子
            q = 1;
            return q;
        }
        if (board[i][1] == board[i][2] && board[i][1] == 1 && board[i][0] == 0)
        {
            board[i][0] =2;
						OLED_chess(i+1,1,'B');//显示棋子
            q = 1;
            return q;
        }
    }
    //判断列是否有机会
    for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] ==1 && board[2][i] == 0)
        {
            board[2][i] = 2;
						OLED_chess(3,i+1,'B');//显示棋子
            q = 1;
            return q;
        }
        if (board[0][i] == board[2][i] && board[0][i] == 1 && board[1][i] == 0)
        {
            board[1][i] = 2;
						OLED_chess(2,i+1,'B');//显示棋子
            q = 1;
            return q;
        }
        if (board[1][i] == board[2][i] && board[1][i] == 1 && board[0][i] == 0)
        {
            board[0][i] = 2;
						OLED_chess(1,i+1,'B');//显示棋子
            q = 1;
            return q;
        }
    }
    //判断正对角线是否有机会
    if (board[0][0] == board[1][1] && board[0][0] == 1 && board[2][2] == 0)
    {
        board[2][2] = 2;
				OLED_chess(3,3,'B');//显示棋子
        q = 1;
        return q;
    }
    if (board[0][0] == board[2][2] && board[0][0] == 1 && board[1][1] == 0)
    {
        board[1][1] = 2;
				OLED_chess(2,2,'B');//显示棋子
        q = 1;
        return q;
    }
    if (board[2][2] == board[1][1] && board[2][2] == 1 && board[0][0] == 0)
    {
        board[0][0] = 2;
				OLED_chess(1,1,'B');//显示棋子
        q = 1;
        return q;
    }
    //判断反对角线是否有机会
    if (board[0][2] == board[1][1] && board[0][2] == 1 && board[2][0] ==0)
    {
        board[2][0] = 2;
				OLED_chess(3,1,'B');//显示棋子
        q = 1;
        return q;
    }
    if (board[0][2] == board[2][0] && board[0][2] == 1 && board[1][1] == 0)
    {
        board[1][1] = 2;
				OLED_chess(2,2,'B');//显示棋子
        q = 1;
        return q;
    }
    if (board[2][0] == board[1][1] && board[2][0] == 1 && board[0][2] == 0)
    {
        board[0][2] = 2;
				OLED_chess(1,3,'B');//显示棋子
        q = 1;
        return q;
    }
    return q;        //不需要防守
}


int IsFull(int board[ROW][COL], int row, int col)//判断棋盘是否排满
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

//判断输赢
//1为玩家
//2为电脑
//3为平局
//4为继续
int judge(int board[ROW][COL], int row, int col)
{
    int i = 0;
    //判断行
    for (i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
        {
            return board[i][0];
        }
    }
    //判断列
    for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)
        {
            return board[0][i];
        }
    }
    //判断对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1]==board[2][0] && board[0][2] != 0)
    {
        return board[0][2];
    }
    //判断棋盘是否满了
    if (IsFull(board, row, col))
    {
        return 3;
    }
    else
        return 4;
}


void Game(void)//游戏入口
{
	int a,b;
	int board[ROW][COL]={{0,0,0},{0,0,0},{0,0,0}};//棋盘
	Game_Init(board,ROW,COL);//初始化棋盘
	
	while (1)
  {
      //玩家下棋+判断
		
      playerA(board, ROW, COL);
		
      ret = judge(board, ROW, COL);
      if (ret != 4)
      {
          break;
      }
      //电脑下棋+判断
      a = attack(board, ROW, COL);
      if (0 == a)
      {
          b = defense(board, ROW, COL);
          if (0 == b)
          {
              playerB(board, ROW, COL);
          }
      }
      ret = judge(board, ROW, COL);
      if (ret != 4)
      {
          break;
      }
	}
	
	if (1 == ret)
  {
			usart2_send((uint8_t*)"bb",2);
  }
  else if (2 == ret)
  {
			usart2_send((uint8_t*)"cc",2);
  }
  else if (3 == ret)
	{
			usart2_send((uint8_t*)"dd",2);
	}
}

void usart2_send(unsigned char *data,unsigned char len)//串口发送字符串
{
		unsigned char t;
		for(t=0;t<len;t++)
        {	
		    while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
            USART_SendData(USART2,data[t]); 				
        }
}
