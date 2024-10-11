#include<stdio.h>
#include<stdlib.h>
#include<math.h> //为了引入pow()

struct Node
{
	int data;
	struct Node* next;
};

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//将元素插入链表(桶)中 
// value 应该是对应的值 那么bin[value] 是对应值的下标
void Insert(struct Node** bin, int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;

	if (bin[value] == NULL) //当这个下标的还未插入数组时
	{
		bin[value] = temp;
	}
	else
	{
		struct Node* p = bin[value];
		while (p->next != NULL) //找到对应位置的最后一个Node
		{
			p = p->next;
		}
		p->next = temp;
	}
}

//这个是基数排序的插入函数 它是根据基数来判断插入的
//index 就是我们所求的基数 
//value 就是我们对应的数的值 这个肯定是不能省略的
void RadixInsert(struct Node** bin, int value, int index)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;

	if (bin[index] == NULL) //当这个下标的还未插入数组时
	{
		bin[index] = temp;
	}
	else
	{
		struct Node* p = bin[index];
		while (p->next != NULL) //找到对应位置的最后一个Node
		{
			p = p->next;
		}
		p->next = temp;
	}
}


// 从链表中移除元素（用于从桶中取出元素） 基数排序也可以使用
int Delete(struct Node** bin, int index)
{
	struct Node* p = bin[index]; //寻找值 记住 bin里面存放的是Node结构体
	bin[index] = bin[index]->next; //类似于头删法 bin[index]的起始 指向下一个节点
	int value = p->data;
	free(p);
	return value;
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



//合并排序  l--左边  r--右边
void Merge(int A[], int l, int mid, int r)
{
	int i=l, j=mid+1, k=l;
	int B[100]; //用来存放 元素的 内存尽量大一点

	//判断条件是 i 小于中位  j 小于右边
	while (i <= mid && j <= r)
	{
		if (A[i] < A[j])
		{
			B[k++] = A[i++]; //比较小的先放入
		}
		else
		{
			B[k++] = A[j++];
		}
	}

	//把还未添完的放入
	for (; i <= mid; i++)
	{
		B[k++] = A[i];
	}
	for (; j <= r; j++)
	{
		B[k++] = A[j];
	}
	//把排列好的元素重新放入
	for (i = l; i <= r; i++)
	{
		A[i] = B[i];
	}
}

//这里的 n 为数组的大小 这个是迭代版本
void IMergeSort(int A[], int n)
{
	int p, l, r, mid, i;

	//这里 p的作用是 用来扩展一个“组”大小的
	//如 2个元素为一组 4 个元素为一组 先从小开始分 然后再合并
	for (p = 2; p <= n; p = p * 2)
	{
		//i+p 为组距
		for (i = 0; i + p - 1 < n; i = i + p)
		{
			l = i; //左边界
			r = i + p - 1; //右边界
			mid = (l + r) / 2; //中间值
			Merge(A, l, mid, r);
		}
	}

	if (p / 2 < n)
	{
		Merge(A, 0, p / 2 - 1, n-1); //大合并
		//p/2 - 1 是下标 要符合
	}
}

//直接输出一个被合并排好序的数组出来
//必须保证 这两个数组本就是排好序的了
void TwoMergeSort(int A[], int B[], int m, int n)
{
	int i, j, k; //作为指针使用
	int C[100];
	i = j = k = 0; //初始一下指向

	while (i < m && j < n)
	{
		if (A[i] < B[j])
		{
			C[k++] = A[i++];
		}
		else
		{
			C[k++] = B[j++];
		}
	}

	//将剩下的填入
	for (; i < m; i++)
	{
		C[k++] = A[i];
	}

	for (; j < n; j++)
	{
		C[k++] = B[j];
	}

	for (int k = 0; k < m + n; k++)
	{
		printf("%d ", C[k]);
	}
	printf("\n");
}


/*
***** 递归 合并排序
我们可以看到，递归合并排序 它是先这个大的数组 不断的 2倍 2倍的缩小。然后直到 一个组里只有 1个元素(Sorted 我们认为它是已经排好序了的).

随后将排好序的数组 递归返回给上一个组里再次进行排序  第一个MergeSort是左子树先排左边 然后在第二个MergeSort排右边
Merge()是实现排序用的 上一节已经实现了
按照高度来看 是 一个高度里面要处理 n个元素

实在不行就画一个树图来模拟 它是一个BST Best Sinary Tree
*/
void RMerge(int A[], int l, int r)
{
	//如果左边小于右边
	int mid;
	if (l < r) //当 l == r 的时候 就是那个递归到只有一个元素的情况 不能再分了
	{
		mid = (l + r) / 2;
		RMerge(A, l, mid);
		RMerge(A, mid + 1, r);
		Merge(A, l, mid, r); //这个是唯一的合并操作
	}
}

//设置一个找到最大值函数 为的是给动态数组给定大小
int FindMax(int A[], int n)
{
	int max = INT_MIN; //这个是要引入<stdlib.h>文件
	int i;
	for (i = 0; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}

	return max;
}

//取余  power 是取决于你要的哪一个位 对应位权上的数
int remainder(int num, int power)
{
	int temp = pow(10, power);
	return (num / temp) % 10;
}

//获取位数
int Bit_Int(int n)
{
	if (n == 0)
		return 1;
	else
		return log10(abs(n)) + 1;//求整数的位数
	//例如  1234  lgx+1;                   
}

void CountSort(int A[], int n)
{
	int i, j, max, * c;
	max = FindMax(A, n);
	c = (int*)malloc(sizeof(int) * (max + 1));

	//将动态数组c里全都赋值为0
	for (i = 0; i < max+1; i++)
	{
		c[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		c[A[i]]++;
	}
	i = 0; j = 0; //初始回0 从头开始
	while (j < max + 1)
	{
		if (c[j] > 0)
		{
			A[i++] = j;
			c[j]--;//里面的次数减1
		}
		else
		{
			j++; //下标移动
		}
	}
}

//桶排序 按实话说 其实它与Count Sort很像
/*
思想:

将数组元素根据范围放入不同的桶（bin）中。
对每个桶内的元素进行排序，然后将它们合并成一个排序好的数组。
*/
void BinSort(int A[], int n)
{
	int max = FindMax(A, n);

	//动态分配空间
	struct Node** Bin = (struct Node**)malloc(sizeof(struct Node*) * (max + 1));

	//初始化每个桶为空
	for (int i = 0; i < max + 1; i++)
	{
		Bin[i] = NULL;
	}

	//将每个对应的元素放入对应的桶中
	for (int i = 0; i < n; i++)
	{
		Insert(Bin, A[i]);
	}

	//按照桶的排序 依次取出并返回数组
	int k = 0;
	for (int j = 0; j < max + 1; j++)
	{
		//判断那个桶是否为空
		//这里的j 就是索引哈
		while (Bin[j] != NULL)
		{
			A[k++] = Delete(Bin, j);
		}
	}
}





//基数排序 
/*
思想:

基数排序是基于“分配”和“收集”的方法进行的排序。它从最低有效位开始逐位对数组进行排序，直到最高有效位。
采用计数排序作为子步骤处理每个位数的排序。

*/
void RadixSort(int A[], int n)
{
	int i, j, max,s; //s 代表次数
	max = FindMax(A, n); //先找到最大值
	s = Bit_Int(max); // 获取需要排序的次数
	//结构体指针数组
	struct Node** Bins = (struct Node**)malloc(sizeof(struct Node*) * 10);

	for (i = 0; i < 10; i++)
	{
		Bins[i] = NULL; //先初始化为空
	}
//这是重复次数 k是重复次数 也是我们用来控制取位的
	for (int k = 0; k < s; k++)
	{
		j = 0; //每一轮都要将它初始化为0
		//先从数组中拿数字
		while (j < n) //n 是数组大小
		{
			int index = remainder(A[j], k);
			RadixInsert(Bins, A[j], index);
			j++; 
		}

		//按照次序取出 返回原先的数组里 
		int num = 0; // 数组的
		for (int w = 0; w < 10; w++)  //遍历10
		{
			while (Bins[w] != NULL)
			{
				A[num++] = Delete(Bins, w);
			}

		}
	}
}


//希尔排序
void ShellSort(int A[], int n)
{
	int gap, i, j,temp;

	for (gap = n / 2; gap >= 1; gap /= 2)
	{

		for (i = gap; i < n; i++)
		{
			temp = A[i]; //与j 隔着 一个gap的距离
			j = i - gap;
			while (j >= 0 && A[j] > temp)
			{
				A[j + gap] = A[j];// 换值
				j = j - gap;
			}
			A[j + gap] = temp;
		}
	}
}


int main()
{
	int A[] = { 3,7,9,10,6,5,12,4,11,2,19 };
	int b[] = { 1,8,45,67,200 };
//适用于快排的数组 最右侧一定是无穷大的数 可以是最大数来替代
	int Q[] = { 3,7,9,10,6,5,12,4,11,2,INT_MAX };
	int L = 11; //长度
	int n = 10;
//	AdvanceBubble(A, 10);
//	QuickSort(Q, 0, 10);
//	Display(Q,11);

//	RMerge(A, 0, 9);
	RadixSort(A, 11);
	Display(A, 11);


//	TwoMergeSort(A, b, 10, 5);
	return 0;
}