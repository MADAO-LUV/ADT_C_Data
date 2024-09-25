#include<stdio.h>
#include<stdlib.h>

struct Array
{
	int A[10];
	int size;
	int length;
};


void Display(struct Array arr)
{
	int i;
	printf("\nElements are\n");
	for (i = 0; i < arr.length; i++)
	{
		printf("%d ", arr.A[i]);
	}
}

void Append(struct Array* arr,int x)
{
	if (arr->length < arr->size)
	{
		arr->A[arr->length++] = x;
	}
}


void Insert(struct Array* arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = x;
		arr->length++;
	}
}


int Delete(struct Array* arr, int index)
{
	int x=0;
	int i;  
	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index; i < arr -> length - 1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->length--;
		return x;
	}
	return 0;
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


/***
Liner Search   线性搜素
1.Transpoistion  转置

2.Move to Head/Font


***/
int LinearSearch(struct Array *arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			swap(&arr->A[i], &arr->A[i - 1]);
			//swap(&arr->A[i], &arr->A[0]);
			//return 0;
			return i-1;
		}
	}
	return -1;
}


/**
Binary Search

1.while() 版本
2.递归版本
**/
int BinarySearch(struct Array arr, int key)
{
	int l, mid, h;
	l = 0;
	h = arr.length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr.A[mid])
		{
			return mid;
		}
		else if (key < arr.A[mid])
		{
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}

int RBinarySearch(int a[], int l, int h, int key)
{
	int mid;

	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
		{
			return mid;
		}
		else if (key < a[mid])
		{
			return RBinarySearch(a, l, mid - 1, key);
		}
		else
		{
			return RBinarySearch(a, mid + 1, h, key);
		}
	}
	return -1;
}

int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
	{
		return arr.A[index];
	}
	return -1;
}


void Set(struct Array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
	{
		arr->A[index] = x;

	}
}


int Max(struct Array arr)
{
	int max = arr.A[0];
	int i;
	for (i = 1; i < arr.length;i++)
	{
		if (arr.A[i] > max)
		{
			max = arr.A[i];
		}
	
	}
	return max;
}

int Min(struct Array arr)
{
	int min = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
		{
			min = arr.A[i];
		}

	}
	return min;
}

int Sum(struct Array arr)
{
	int s = 0;
	int i;
	for (i = 0; i < arr.length; i++)
	{
		s += arr.A[i];
	}

	return s;
}


float Avg(struct Array arr)
{
	return (float)Sum(arr) / arr.length;
}


//翻转程序
void Reverse(struct Array* arr)
{
	int* B;
	int i, j;

	B = (int*)malloc(arr->length * sizeof(int));
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->A[i];
	}
	//上面是在B中保存翻转后的数组A
	for (i = 0; i > arr->length; i++)
	{
		arr->A[i] = B[i];
	}
}

void Reverse2(struct Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		swap(&arr->A[i], &arr->A[j]);
	}

}

//按序插入
void InsertSort(struct Array* arr, int x)
{
	int i = arr->length - 1;
	if (arr->length == arr->size)
	{
		return; //结束运行
	}
	while (i >= 0 && arr->A[i] > x)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;
}

//是否排序 函数
int isSorted(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
		{
			return 0;
		}
	}
	return 1;
}


// 正负分区 正数在右边 负数在右边
void REarrange(struct Array* arr)
{
	int i, j;
	i = 0;
	j = arr->length - 1;

	while (i < j)
	{
		while (arr->A[i] < 0)i++;
		while (arr->A[j] >= 0)j--;
		if (i < j)swap(&arr->A[i], &arr->A[j]);
	}
}

//数组合并函数  返回类型是 结构指针
struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
		}
		else
		{
			arr3->A[k++] = arr2->A[j++];
		}
	}
	//按序复制
	//其中一个完成了便将剩下的复制进去，复制完的不会继续执行for循环
	for (; i < arr1->length; i++)
	{
		arr3->A[k++] = arr1->A[i];
	}

	for (; j < arr2->length; j++)
	{
		arr3->A[k++] = arr2->A[j];
	}
	//下面的不能缺少，不然正常显示 具体可以看Display()函数写法
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;

	return arr3;
}




int main()
{
	struct Array arr1 = { {2,6,10,15,25},10,5 };
	struct Array arr2 = { {3,4,7,18,20},10,5 };
	struct Array* arr3;
	
	arr3 = Merge(&arr1, &arr2);
	Display(*arr3);

	return 0;

}
