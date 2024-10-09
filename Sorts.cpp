#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}




//输出数组
void Display(int A[],int n)
{
	int len = sizeof(A);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

//初级 冒泡排序
void Bubble(int A[], int n)
{
	int i, j;

	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j+1])
			{
				swap(&A[j], &A[j+1]);
			}
		}
	}
}

//优化版 冒泡排序
/*
优化的地方:
如果是普通版的冒泡排序，当我们传入的是已经排好序的数组
我们仍然要遍历完数组n^2次。

而我们加入了一个标志flag  只要flag==0 没有进行初始一次都没有进行comprasion的话，
就说明它是排序好了的，我们就直接break 减少时间的浪费
*/
void AdvanceBubble(int A[], int n)
{
	int i, j,flag;

	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}	

		}
		if (flag == 0)
		{
			break;  //如果一直没有进入comparison的话就退出
		}
	}
}

//插入排序
void InsertionSort(int A[], int n)
{
	int i, j, x;

	for (i = 1; i < n; i++)
	{
		j = i - 1;  //使 j 为 i的前一个数的下标
		x = A[i];  //用来记录当前的数

//此处的判断是 j下标要大于-1 不然就越界了 （上溢）
// A[j] > x 是 如果 x 比前面已经排序好的还小就往前移动

		while (j > -1 && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x; //将空出来的位置填入 用来抵消 已经j--的位置
	}


}


//选择排序
void SelectionSort(int A[], int n)
{
	int i, j, k; //用做指针用途

	for (i = 0; i < n - 1; i++)
	{

		for (j = k = i; j < n; j++)
		{
			if (A[j] < A[k])
			{
				k = j; //交换位置
			}
			
		}
		//直到一轮遍历结束后，再进行交换位置
		swap(&A[i], &A[k]); //交换位置
	}
}


//分区 函数 r是 下标
int Partition(int A[], int l, int r)
{
	int pivot = A[l];
	int i = l, j = r; //j 是这个相对最右边

	do {
		do { i++; } while (A[i] <= pivot); //左边的数 要 小于等于 pivot 
		do { j--; } while (A[j] > pivot);  //右边的数 要 大于pivot
	//以起到分区的作用
	
		if (i < j)swap(&A[i], &A[j]); //交换位置
	} while (i < j);

	swap(&A[l], &A[j]); //最后 将pivot 与 j交换位置
	return j; //返回最后停止的位置

}

//这个就和小学生排队一样
//每个人以自己为标杆 去到自己应该去的地方。 
//分成了一个个pivot 最后就排好序了
//r是下标   然后显示 该排列好的数组 亦可以缩短1个长度 INT_MAX没必要显示出来
void QuickSort(int A[], int l, int r)
{
	int j;

	if (l < r)
	{
		j = Partition(A, l, r); //获取 当前标杆的位置
		QuickSort(A, l, j); //以标杆位置为分界 左边进行快排
		QuickSort(A, j + 1, r);  // 以标杆+1为起始，右边进行快排
	}

}



//优化后的冒泡排序

int main()
{
	int A[] = { 3,7,9,10,6,5,12,4,11,2 };

//适用于快排的数组 最右侧一定是无穷大的数 可以是最大数来替代
	int Q[] = { 3,7,9,10,6,5,12,4,11,2,INT_MAX };
	int L = 11; //长度
	int n = 10;
//	AdvanceBubble(A, 10);
	QuickSort(Q, 0, 10);
	Display(Q,11);

	return 0;
}