#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}

}
void  DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j= 0;
	for (i = 0;i <= col;i++)//打印列号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");

	}
	printf("\n");

}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//生成1-9随机数
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	} 

}
int  get_mine_count(char mine[ROWS][COLS], int x,int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';

}

void  FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)//当除了雷之外所有的排查完=排查成功
	{
		printf("请输入要排查的坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标合法性
		{
			if (mine [x][y] == '1')                //1.第一次是雷    
			{
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine,row,col);
				break;
			}
			else                                     //2.第一次不是雷
			{
				int count =get_mine_count(mine, x, y);//计算x,y周围有多少雷（单独实现这个函数）
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你排雷成功！\n");
		DisplayBoard(mine, row, col);//排雷成功后把雷的信息图打印出来看一下
	}
}