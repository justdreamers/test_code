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
//char* my_strcpy(char* dest,const char* src)//��Դͷ����Ϊ���ɸı�
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src!= NULL);//����
//	while (*dest++ = *src++)//��srcָ����ַ���������destָ��Ŀռ䣬����\0
//	{
//		;
//	}
//	return ret;
//}
//	
//int main()
//{     //�ַ������� strcpy
//	char arr1[] = "#############";
//	char arr2[] = "bit";
//
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}
//int my_strlen(const char*str)//���ַ������ȣ���ϣ�����ı����const
//{
//	int count = 0;
//	assert(str != NULL);//����ָ�����Ч�ԣ�����Ϊ��ָ��
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
	printf("��������������");
	int a = 0;
	int b = 0;
	scanf("%d%d", &a,&b);
	int sum=Add(a, b);
	printf("sum=%d\n", sum);
	return 0;
}
