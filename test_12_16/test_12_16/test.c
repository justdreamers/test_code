#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()
//{
//	int num = 0;
//	int* p = &num;
//	*p = 20;
//	printf("%d\n", num);
//	return 0;
//}
//char* my_strcpy(char* dest,const char* src)//将源头设置为不可改变
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src!= NULL);//断言
//	while (*dest++ = *src++)//将src指向的字符串拷贝到dest指向的空间，包含\0
//	{
//		;
//	}
//	return ret;
//}
//	
//int main()
//{     //字符串拷贝 strcpy
//	char arr1[] = "#############";
//	char arr2[] = "bit";
//
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}
//int my_strlen(const char*str)//求字符串长度，不希望被改变加上const
//{
//	int count = 0;
//	assert(str != NULL);//保持指针的有效性，不能为空指针
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len =my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	printf("请输入两个数：");
	int a = 0;
	int b = 0;
	scanf("%d%d", &a,&b);
	int sum=Add(a, b);
	printf("sum=%d\n", sum);
	return 0;
}
