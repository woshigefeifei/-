#define _CRT_SECURE_NO_WARNINGS 1 
#include"game.h"


void game()
{
	char ret = 0;
	srand((unsigned int)time(NULL));
	char arr[row][col] = { 0 };
	intboard(arr, row, col);//初始化数组
	board(arr, row, col);//生成棋盘
	while (1)
	{
		move(arr, row, col);//玩家的回合下棋
		board(arr, row, col);
		ret = iswin(arr, row, col);
		if (ret != 'C')
			break;
		move2(arr, row, col);//电脑的回合下棋
		board(arr, row, col);
		ret = iswin(arr, row, col);
		if (ret != 'C')
			break;

	}
	if (ret == '*')
		printf("玩家赢了!\n");
	else if (ret == '#')
		printf("电脑赢了!\n");
	else
		printf("平局\n");
}
void menu()//选择菜单
{
	int choose = 0;
	do
	{
		printf("******************************\n");
		printf("********1.play  0.exit *******\n");
		printf("******************************\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("那我们就开始van♂游♂戏♂吧\n");
			game();
			break;
		case 0:
			printf("不玩啊，那滚吧\n");
			break;
		default:
			printf("你选错了宝贝儿，再选一次吧~~\n");
			break;
		}
	} while (choose);
}
void test()
{
	menu();
}
int main()
{

	test();
	return 0;
}