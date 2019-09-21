#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)  //��ʼ������
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
void ShowBoard(char board[ROW][COL], int row, int col) //��ӡ����
{
	//��ӡ����
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
		//��ӡ����
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
void PlayerMove(char board[ROW][COL], int row, int col) //�����
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)     //�ж������Ƿ�ռ��
		{
			if (board[x - 1][y - 1] == ' ')   //δ��ռ�ã���ֵΪ*
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else     //���걻ռ��
			{
				printf("���걻ռ�ã�����������!\n");

			}

		}
		else  //�������겻��ȷ
		{
			printf("����Ƿ�������������!\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)//������
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
	while (1)
	{
		//randΪ�������������
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')  //�ж������Ƿ�ռ��
		{
			board[x][y] = '#';   //��ֵ#
			break;
		}
	}
}
int  IsFull(char board[ROW][COL], int row, int col)  //�ж������Ƿ���������Ϊ֧��CheckWin������
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
int  IsWin(char board[ROW][COL], int row, int col) //�ж���Ӯ
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
	if (IsFull(board, row, col))  //ƽ��
	{
		return 'W';
	}
	return ' ';
}
