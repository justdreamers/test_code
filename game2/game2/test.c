#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("###########################\n");
	printf("######    1.play      #####\n");
	printf("######    0.exit      #####\n");
	printf("###########################\n");
}
void game()
{           //�׵���Ϣ�洢
	char mine[ROWS][COLS] = {0};      //���ú��׵���Ϣ
	char show[ROWS][COLS] = {0};      //�Ų���׵���Ϣ

	InitBoard(mine, ROWS, COLS,'0'); //��ʼ�����̣�Ҫʵ���������Ҫ��game.h������game.c�ﹹ��
	InitBoard(show, ROWS, COLS,'*');

	DisplayBoard(mine, ROW, COL);    //��ӡ����  ֻ��ӡ9*9�ĸ���
	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW, COL);         //������//DisplayBoard(mine, ROW, COL);���ú��׿��Լ��һ��
	//DisplayBoard(mine, ROW, COL);
	FindMine(mine,show,ROW,COL);        //����
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
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
			printf("�˳���Ϸ:>\n");
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}