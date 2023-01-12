#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		*(p + 1) = 1;
	}

	return 0;
}
//struct stu
//{
//	char name[20];
//	int age;
//	char id[20];
//};
//int main()
//{
//	struct stu s1 ={ "李四", 20, "2001010130" };
//	struct stu *ps= &s1;
//	printf("%s\n", ps->name);   //printf("%s\n", (*ps).name);
//	printf("%d\n", ps->age);  //printf("%d\n", (*ps).age);
//	printf("%s\n", ps->id); //printf("%s\n", (*ps).id);
//
//	//printf("%s\n", s1.name);
//	//printf("%d\n", s1.age);
//	//printf("%s\n", s1.id);
//
//	return 0;
//}
//int get_max(int x, int y)
//{
//	return x > y ? x : y;
//
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个数：>");
//	scanf("%d%d", &a, &b);
//	int max=get_max(a, b);
//	printf("%d\n", max);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int b = 10;
//	printf("%d\n", ++a);
//	printf("%d\n", b++);
//	return 0;
//}