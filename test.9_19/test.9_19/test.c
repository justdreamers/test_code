#include <stdio.h>
#include<string.h>

int sum(int a)
{
	int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return (a+b+c);
}
int main()
{
	int i;
	int a = 2;
	for (i = 0;i < 5;i++)
	{
		printf("%d", sum(a));
	}
	return 0;
}
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar  (ch);
//		//printf("%d   ", i);
//	//	i++;
//	}
//	return 0;
//}   