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
{           //雷的信息存储
	char mine[ROWS][COLS] = {0};      //布置好雷的信息
	char show[ROWS][COLS] = {0};      //排查出雷的信息

	InitBoard(mine, ROWS, COLS,'0'); //初始化棋盘；要实现这个函数要在game.h声明，game.c里构造
	InitBoard(show, ROWS, COLS,'*');

	DisplayBoard(mine, ROW, COL);    //打印棋盘  只打印9*9的格子
	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW, COL);         //布置雷//DisplayBoard(mine, ROW, COL);布置好雷可以检查一下
	//DisplayBoard(mine, ROW, COL);
	FindMine(mine,show,ROW,COL);        //找雷
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏:>\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}