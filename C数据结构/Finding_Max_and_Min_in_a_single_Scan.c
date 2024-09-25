#include<stdio.h>

/*
通过一次Scan 来找出 最大值和最小值

通过if...else if 中 大小比较的先后顺序
Best: Compare = n - 1 从大到小排序好
Worst； Compare = 2(n-1) 从小到大排序
*/

//n为数组的大小
void Find_MAXORMIN(int A[], int n)
{
	int min = A[0];
	int max = A[0];

	for (int i = 0; i < n; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
		else if (A[i] > max)
		{
			max = A[i];
		}
	}
//结束循环遍历后

	printf("MAX: %d  MIN: %d ", max, min);
}


int main()
{
	int A[10] = { 5,1,-1,7,9,10,51,-20,4,19 };
	Find_MAXORMIN(A, 10);
	return 0;
}