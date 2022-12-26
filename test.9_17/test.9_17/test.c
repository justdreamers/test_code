#include<stdio.h>
#include<string.h>
extern int Add(int x, int y);
int main()
{
	int a = 10;
	int b = 20;
	int sum =Add(a, b);
	printf("sum=%d\n", sum);
	return 0;
}
//int main()
//{
//	extern int  g_val;
//	printf("g_val=%d\n", g_val);
//	return 0;
//}