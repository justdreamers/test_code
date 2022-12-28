#define  _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include<stdio.h>
int binary_search(int arr[], int k,int sz)
{
	//int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	//int mid = (left + right) / 2;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}

	}
	return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k =17;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret =binary_search(arr, k,sz);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
	}
	return 0;
}
//int is_leap_year(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000;year <= 2000;year++)
//	{
//		if (is_leap_year(year) == 1)
//		{ 
//			printf("%d  ", year); 
//			count++;
//		}
//		
//	}
//	printf("\n\n\ncount=%d\n", count);
//	return 0;
//}

//int is_prime(int x)
//{
//	int j = 0;
//	for (j =2;j < x;j++)
//	{
//		if (x % j == 0)
//			return 0;	   
//	}
//	return 1;
//
//}
//int main()
//{
//	int i = 0;
//	for (i = 100;i <= 200;i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d  ", i);
//	}
//	return 0;
//}
//void Swap(int* pa, int* pb)//int*pa=&a,
//{
//	int tmp = 0;
//	tmp = * pa;
//	* pa = * pb;
//	* pb = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a=%db=%d\n", a, b);
//	Swap(&a, &b);//因为没有返回值所以不设置返回类型
//	printf("a=%db=%d\n", a, b);
//	return 0;
//}
//int get_max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个数：");
//	scanf("%d%d", &a, &b);
//	int max = get_max(a, b);
//	printf("max=%d\n", max);
//	return 0;
//}
//int main()
//{
//	char arr[] = { "hello world" };
//	memset(arr, '*', 5);
//	printf("%s\n",arr);
//	return 0;
//}
//int main()
//{
//	char arr1[] = { "bit" };
//	char arr2[20] = { "##########" };
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入数字：");
//	scanf("%d%d", &a, &b);
//	int sum=Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}