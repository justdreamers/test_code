#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int day = 0;
	printf("请输入一个数：\n");
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("星期1\n");
		break;
   case 2: 
		printf("星期2\n");
		break;
	case 3:
		printf("星期3\n");
		break;
    case 4:
		printf("星期4\n");
		break;
	case 5:
		printf("星期5\n");
		break;
	case 6:
		printf("星期6\n");
		break;
	case 7:
		printf("星期7\n");
		break;
	}
	return 0;

}

//{
//	int a = 1;
//	while (a <= 100)
//	{
//		/*printf("%d ", a);
//		a += 2;*/
//		if (a % 2 != 0)
//		////if (a % 2 == 1)
//	      printf("%d    ", a);
//	        a++;
//	}
//	return 0;

//}