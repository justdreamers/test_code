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
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i <= col;i++)//用来打印列号
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1;j <= col;j++)
		{
			printf("%c ",board[i][j]);//打印每一行的数

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


int get_mine_count(char mine[ROWS][COLS],int  x,int  y)
{
	return mine[x-1][y] +
		mine[x-1][y-1] +
		mine[x][y-1] +
		mine[x+1][y-1] +
		mine[x+1][y] +
		mine[x+1][y+1] +
		mine[x][y+1] +
		mine[x-1][y+1] - 8 * '0';

		 
}
//统计show中'*'的数量，当count的数量是布置雷的数量也就是说你排完了所有的雷
int count_mine(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
				count++;
		}
	}
	return count;
}
//递归扩展排雷：
void Extend_board(char mine[ROWS][COLS], char show[ROWS][COLS], char contrast[ROWS][COLS], int row, int col)
{
	if (get_mine_count(mine, row, col) == 0)
	{
		for (int i = row - 1; i <= row + 1; i++)  //限制范围
		{
			for (int j = col - 1; j <= col + 1; j++) 
			{
				show[i][j] = (get_mine_count(mine, i, j) + '0'); 
				if (show[i][j] == '0' && contrast[i][j] != '$') 
				{
					contrast[i][j] = '$'; //将该位置标在contrast数组中，并且作为递归的停止条件
					Extend_board(mine, show, contrast, i, j); //调用递归函数再次进行判断
				}
			}
		}
	}
	else
		show[row][col] = (get_mine_count(mine, row, col) + '0');
	return;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], char contrast[ROWS][COLS],int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win != EASY_COUNT)
	{
		printf("请输入要排查的坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine,row,col);
				break;
			}
			else
			{
				contrast[x][y] = '$';
				Extend_board(mine, show, contrast, x, y);
				int count = get_mine_count(mine, x, y);
				DisplayBoard(show, row, col);	
				win=count_mine(show,row,col);
			}
		}
		else
		{
			printf("非法坐标请重新输入！\n");
		}
    }
	if (win ==  EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
		DisplayBoard(mine, row, col);
	}

}