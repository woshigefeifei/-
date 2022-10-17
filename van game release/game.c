#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void intboard(char arr[row][col], int a, int b)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void board(char arr[row][col], int a, int b)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		printf("\n");
	}
}
void move(char arr[row][col], int a, int b)
{
	int i = 0;
	int j = 0;
	printf("玩家走\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			if (arr[i - 1][j - 1] == ' ')
			{
				arr[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("该坐标已被占用，请重新输入\n");
		}
		else
		{
			printf("输入的坐标违法，请重新输入\n");
		}
	}
}
void move2(char arr[row][col], int a, int b)
{
	int i = 0;
	int j = 0;
	printf("电脑走\n");
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (arr[i][j] == ' ')
		{
			arr[i][j] = '#';
			break;
		}
	}
}
int isfull(char arr[row][col], int a, int b)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char iswin(char arr[row][col], int a, int b)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] != ' ')
			return arr[i][0];
	}
	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] != ' ')
			return arr[0][i];
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != ' ')
		return arr[1][1];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != ' ')
		return arr[1][1];
	if (1 == isfull(arr, row, col))
		return 'Q';
	return 'C';
}
