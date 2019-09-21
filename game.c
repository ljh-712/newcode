#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)  //初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void ShowBoard(char board[ROW][COL], int row, int col) //打印棋盘
{
	//打印数据
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印棋盘
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col) //玩家走
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)     //判断坐标是否被占用
		{
			if (board[x - 1][y - 1] == ' ')   //未被占用，赋值为*
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else     //坐标被占用
			{
				printf("坐标被占用，请重新输入!\n");

			}

		}
		else  //输入坐标不正确
		{
			printf("坐标非法，请重新输入!\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)//电脑走
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		//rand为生成随机数函数
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')  //判断坐标是否被占用
		{
			board[x][y] = '#';   //赋值#
			break;
		}
	}
}
int  IsFull(char board[ROW][COL], int row, int col)  //判断棋盘是否已满（仅为支持CheckWin函数）
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
int  IsWin(char board[ROW][COL], int row, int col) //判断输赢
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' '))
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] != ' '))
		{
			return board[0][i];
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != ' '))
	{
		return board[0][0];
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != ' '))
	{
		return board[0][2];
	}
	if (IsFull(board, row, col))  //平局
	{
		return 'W';
	}
	return ' ';
}
