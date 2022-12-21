#define _CRT_SECURE_NO_WARNINGS 1
#include<math.h>
#include<stdio.h>
int main()
{
	int i = 0;
	int arr[] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
	int max = arr[0];                     //应该假设数组中的某个元素为最大值
	int sz = sizeof(arr) / sizeof(arr[0]);//计算元素个数
	for (i = 1;i <sz;i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("max=%d\n", max);
	return 0;
}




//int main()
//{
//	int i = 0;
//	int flag = 1;
//	double sum = 0.0;
//	for (i = 1;i <= 100;i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int  count = 0;
//	for (i=1;i <= 100;i++)
//	{
//		if (i%10 == 9)
//			count++;
//		if (i/10 == 9)
//			count++;
//	}
//	printf("count=%d\n",count);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100;i <= 200;i++)
//	{
//		int j = 0;
//		for (j = 2;j <=sqrt(i);j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//		   }
//		}
//		if (j > sqrt(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//int main()
//{
//	int year = 0;
//	int count = 0;
//	
//	for (year = 1000;year <= 2000;year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
	//{
	//	if (year % 4 == 0 && year % 100 != 0)
	//	{
	//		printf("%d ", year);
	//		count++;
	//	}
	//	else if (year % 400 == 0)
	//	{
	//		printf("%d ", year);
	//		count++;
	//	}
	//}
//	printf("\ncount=%d\n", count);
//	return   0;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//	while (m % n)
//	{
//		r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1;i < 100;i++)
//	{
//		if (i % 3 == 0)
//			printf("%d  ", i);
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d",&a,&b,&c);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}