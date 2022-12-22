#include<stdio.h>
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		int flag = 0;//假设冒泡排序这一趟已经有序
		int j = 0;
		int tmp = 0;
		for (j = 0;j < sz - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//当flag=0,说明数据没有有序，进入循环后有序然后赋值0

			}
		}
		if (flag == 1)//如果flag=1，说明有序，程序结束
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}