#include<stdio.h>
void bubble_sort(int arr[],int sz)
{
	int i = 0;
	//int sz = sizeof(arr)/sizeof(arr [0]);
	for (i = 0;i < sz-1;i++) //确定冒泡的趟数
	{
		int j = 0;
		for (j = 0;j < sz - 1 - i;j++)//每一趟冒泡排序
		{
			if (arr[j] > arr[j + 1])
			{
				 int tmp = arr[j];
				 arr[j] = arr[j +1];
				 arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);//sz在外面算出再传进去
     bubble_sort(arr,sz);//冒泡排序函数
	 //arr是数组，对数组arr传参实际上传的是数组arr的首元素地址  &arr
	 for (i = 0;i < sz;i++)
	 {
		 printf("%d  ", arr[i]);
	 }
	return 0;
}