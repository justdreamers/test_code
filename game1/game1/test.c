#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("######################################\n");
	printf("######1.��ʼ��Ϸ   0.������Ϸ ########\n");
	printf("######################################\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//�������ߵ�������Ϣ
	InitBoard(board, ROW, COL);//��ʼ������,��һ������������ʲô���ݶ����ʼ��Ϊ�ո�
	DisplayBoard(board, ROW, COL);  //��ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);   //�������
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);                   //�ж�����Ƿ�Ӯ
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//��������
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);                      //�жϵ����Ƿ�Ӯ
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//����һ�����ֵ
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			break;
		}
	} while (input);//input Ϊ0��Ϊ�ټ��˳���Ϸ��Ϊ1��Ϊ�棻����ѭ��
}
int main()
{
	test();
	return 0;
}