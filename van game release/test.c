#define _CRT_SECURE_NO_WARNINGS 1 
#include"game.h"


void game()
{
	char ret = 0;
	srand((unsigned int)time(NULL));
	char arr[row][col] = { 0 };
	intboard(arr, row, col);//��ʼ������
	board(arr, row, col);//��������
	while (1)
	{
		move(arr, row, col);//��ҵĻغ�����
		board(arr, row, col);
		ret = iswin(arr, row, col);
		if (ret != 'C')
			break;
		move2(arr, row, col);//���ԵĻغ�����
		board(arr, row, col);
		ret = iswin(arr, row, col);
		if (ret != 'C')
			break;

	}
	if (ret == '*')
		printf("���Ӯ��!\n");
	else if (ret == '#')
		printf("����Ӯ��!\n");
	else
		printf("ƽ��\n");
}
void menu()//ѡ��˵�
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
			printf("�����ǾͿ�ʼvan���Ρ�Ϸ���\n");
			game();
			break;
		case 0:
			printf("���氡���ǹ���\n");
			break;
		default:
			printf("��ѡ���˱���������ѡһ�ΰ�~~\n");
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