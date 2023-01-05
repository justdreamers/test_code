#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu()
{
	printf("********************************\n");
	printf("****         1.play        *****\n");
	printf("****         2.exit        *****\n");
	printf("********************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//创建数组
	char show[ROWS][COLS] = { 0 };
	char contrast[ROWS][COLS] = { 0 };

	InitBoard(mine, ROWS, COLS,'0');//初始化棋盘
	InitBoard(show, ROWS, COLS,'*');

	DisplayBoard(mine,ROW,COL);//打印棋盘 9*9
	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW, COL);//放雷
	//DisplayBoard(mine, ROW, COL);//这个用于测试是需要看雷在哪里

	FindMine(mine, show,contrast, ROW, COL);//找雷

}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏：>\n");
			break;
		default:
			printf("选择错误，请重新选择！>\n");
			break;
		}
	}while (input);


}
int main()
{

	test();
	return 0;
}