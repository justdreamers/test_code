#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int n = 0;
	int b= 1;
	printf("������һ������");
	scanf("%d",& n);
	for (i = 1;i <= n;i++)
	{
		b= b * i;
	}
	printf("b�Ľ׳�=%d\n",b);
	return 0;
}
//int main()
//{
//	char ch = 'A';
//	printf("%c\n", ch);
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	} 
//	while (i <=10);
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1;i <= 10;i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}
////
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
////}
//int main()
//{
//	int ch = 0;
//	int ret = 0;
//	char password[20] = { 0 };
//	printf("����������:>");
//	scanf("%s", password);
//	while ((ch= getchar()) !='\n' )
//	{
//		;
//	}
//	printf("��ȷ��(Y/N):>");
//	ret=getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//	return 0;
//}
//{
//	int ch = 0;
//	while ((ch = getchar() )!= EOF)
//	{
//		putchar(ch);
//	}
//
//	return 0;
//}