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
	for (i = 0;i <= col;i++)//������ӡ�к�
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (j = 1;j <= col;j++)
		{
			printf("%c ",board[i][j]);//��ӡÿһ�е���

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
		int x = rand() % row + 1;//����1-9�����
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
//ͳ��show��'*'����������count�������ǲ����׵�����Ҳ����˵�����������е���
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
//�ݹ���չ���ף�
void Extend_board(char mine[ROWS][COLS], char show[ROWS][COLS], char contrast[ROWS][COLS], int row, int col)
{
	if (get_mine_count(mine, row, col) == 0)
	{
		for (int i = row - 1; i <= row + 1; i++)  //���Ʒ�Χ
		{
			for (int j = col - 1; j <= col + 1; j++) 
			{
				show[i][j] = (get_mine_count(mine, i, j) + '0'); 
				if (show[i][j] == '0' && contrast[i][j] != '$') 
				{
					contrast[i][j] = '$'; //����λ�ñ���contrast�����У�������Ϊ�ݹ��ֹͣ����
					Extend_board(mine, show, contrast, i, j); //���õݹ麯���ٴν����ж�
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
		printf("������Ҫ�Ų�����꣺>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը���ˣ�\n");
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
			printf("�Ƿ��������������룡\n");
		}
    }
	if (win ==  EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		DisplayBoard(mine, row, col);
	}

}