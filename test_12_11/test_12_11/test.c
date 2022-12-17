#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//count_bit_one( int a)
//{
//	int count = 0;
//	while (a)
//	{
//		a = a & (a - 1);
//		count++;
//	}
//	/*int count = 0;
//	int i = 0;
//	for (i = 0;i < 32;i++)
//	{
//		if( ((a >> i) & 1) == 1)
//		{
//			count++;
//	    }
//	}*/
//	/*while (a)
//	{
//
//		if (a % 2 == 1)
//		{
//			count++;
//		}
//		a = a / 2;
//	}*/
//	return count;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int count=count_bit_one(a);
//	printf("count=%d\n", count);
//	return 0;
//}
//int get_differ_number(int m,int n)
//{
//	int tmp = m ^ n;
//	int count = 0;
//	while (tmp)
//	{
//		tmp = tmp & (tmp - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &m, &n);
//	int count=get_differ_number(m, n);
//	printf("count=%d\n", count);
//}
//void print(int a)
//{
//	int i = 0;
//	printf("奇数位：\n");
//	for (i = 30;i >= 0;i -= 2)
//	{
//		printf("%d ", ((a >> i) & 1));
//	}
//	printf("\n");
//
//	printf("偶数位：\n");
//	for (i = 31;i >= 1;i -= 2)
//	{
//		printf("%d ", ((a >> i) & 1));
//	}
//	printf("\n");
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//void print_table(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1;i <= n;i++)
//	{
//		for (j = 1;j <= i;j++)
//		{
//			printf("%d*%d=%-3d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_table(n);
//	return 0;
//}
//#include<string.h>
// int my_strlen(char*str)
//{
//	 int count = 0;
//	 while (*str != '\0')
//	 {
//		 count++;
//		 str++;
//	 }
//	 return count;  
//}
//void reverse_string(char *arr)
//{
//	    char tmp = arr[0];
//		int len = my_strlen(arr);
//		arr[0] = arr[len - 1];
//		arr[len - 1] = '\0';
//		if (my_strlen(arr+1) >= 2)
//		{
//			reverse_string(arr + 1);
//		}
//		arr[len - 1] = tmp;
//
//}
//int main()
//{
//	char arr[] = "abcdefgh";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}
//int  Digitsum(unsigned int num)
//{
//	if (num > 9)
//	{
//		return  Digitsum(num/10) + num%10;
//	}
//	else
//	{
//		return num;
//	}
//}
//int main()
//{
//	unsigned int num = 0;
//	printf("请输入数字：\n");
//	scanf("%d", &num);
//	int ret=Digitsum(num);
//	printf("ret=%d\n", ret);
//	return  0;
//
double  Pow(int n, int k)//n^m=n*(m-1)
{
	if (k < 0)
		return (1.0 / (Pow(n, -k)));
	else if (k == 0)
		return 1;
	else
		return n * Pow(n, k - 1);
}
int main()
{
	int n = 0;
	int k= 0;
	scanf("%d%d", &n, &k);
	double ret=Pow(n, k);
	printf("ret=%lf\n", ret);
	return 0;
}