#include<stdio.h>
#include<stdlib.h>
// 这里的 n为索引
void Insert(int H[], int n)
{
	int i = n, temp;
	temp = H[i];

	while (i > 1 && temp > H[i / 2])
	{
		H[i] = H[i / 2];
		i = i / 2;
	}
	H[i] = temp;

}

//这里是将 n处的值 与 头部值进行对换 头部的值然后放到所对应的n处
int Delete(int A[], int n)
{
	int i, j, x,temp,val;
	val = A[1];
	x = A[n]; //先用来保存要删除的元素
	A[1] = A[n];   //将这个元素移动到 堆头
	A[n] = val;
	i = 1; j = i * 2;

	while (j < n - 1)
	{
		if (A[j + 1] > A[j]) //这里是两个子节点进行对比
			j = j + 1;
		if (A[i] < A[j]) //这里是父节点与子节点进行对比
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
//--------------这里---上面是父与子交换 下面是去到子节点位置
			i = j;
			j = 2 * j;
		}
		else
		{
			break;
		}
		
	}
	return val;
}

//返回堆的长度,因为将头部的值 忽略掉 所以 长度要减去1.
int Length(int A[])
{
	return sizeof(A)-1;
}

void CreatHeap(int* A)
{
	int len = Length(A);

	for (int i = 2; i <= len; i++)
	{
		Insert(A, i);
	}
}

//堆排序
void HeapSort(int* A)
{
	int len = Length(A); //返回长度

	for (int i = len; i > 1; i--)
	{
		Delete(A, i);
	}
	for (int i = 1; i <= len; i++)
	{
		printf("%d ", A[i]);
	}
}


int main()
{
	int len;
	int H[] = { 0,10,20,30,25,5,40,35};
	len = Length(H);
	printf("%d ", Length(H));
	printf("\n");
	CreatHeap(H);
	HeapSort(H);

	return 0;
}