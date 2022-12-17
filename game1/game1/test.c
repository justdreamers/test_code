#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("######################################\n");
	printf("######1.开始游戏   0.结束游戏 ########\n");
	printf("######################################\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//数组存放走的棋盘信息
	InitBoard(board, ROW, COL);//初始化棋盘,这一步是无论数组什么数据都会初始化为空格
	DisplayBoard(board, ROW, COL);  //打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);   //玩家下棋
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);                   //判断玩家是否赢
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);                      //判断电脑是否赢
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//设置一个随机值
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
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);//input 为0，为假即退出游戏；为1即为真；进入循环
}
int main()
{
	test();
	return 0;
}