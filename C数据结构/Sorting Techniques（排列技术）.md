Critera for analysis(分析标准)
1.Number of Comparisons
2.Number of swaps
3.Adaptive
4.stable
5.Extra Memory（额外内存需要）
![[Pasted image 20241009112248.png]]
以上排序方法。

1-8 的排序
是 Comparison based Sorts (以比较为基础的排序)

9-11 的排序
是以 Index Based Sorts(以检索为基础的排序)

![[Pasted image 20241009113047.png]]

1.Bubble Sort(冒泡排序)
![[Pasted image 20241009113649.png]]


2.Insertion Sort(插入排序)\
![[Pasted image 20241009134823.png]]
插入排序更适合链表，因为链表不需要移动后面的元素。
而列表需要移动后面的元素
O(n^2)

插入排序是从第二个元素开始的。第一个元素默认已经排好序

![[Pasted image 20241009140210.png]]
插入排序 适应性(adapitive)
当数组A已经是排好序的情况下 
它是适应已经排好序的数组的，所以并没有像Bubble一样引入 flag来进行判断
number of comparison--n-1次
numberi of swap---1 次

最坏的情况是它是逆序排列的数组
![[Pasted image 20241009175958.png]]
Bubble sort 和 Insertion Sort 进行比较


Selection Sort(选择排序)
需要三个指针 分别指向数组里的元素
Comparison : n(n-1)/2
Swap: n -1 

![[Pasted image 20241009181151.png]]

i 指向 需要被交换的元素， j，k进行比对 选择出最小的那个元素。 然后进行交换。

k 和 i 刚开始都指向同一个数， 如果没有比k更小的数出现 就不进行交换。

adaptive 适应性
stable 稳定


Quick Sort(快排)
使得中间的元素处于静态位置，前面的元素要都比这个元素小，后面的元素都要比这个元素大

找到privte元素 比他小的去到它的前面， 否则就再后面不动

![[Pasted image 20241009183506.png]]
这里可以看到我们找到的那个private元素 以它为分界 前面的是比它小的 ， 后面的是比它大的，。
然后再分别对两个区域又进行一次快速排序。

![[Pasted image 20241009184336.png]]

最坏的情况就是数组是已经排好序的情况。

![[Pasted image 20241009190128.png]]
进行调用

Best case(最好的情况)
分区只发生在中间

Worst Case(最坏的情况)
分区发生在一边

平均时间是O(nlogn)
它一共有两个模块 1.分区 2.递归快速排序

数组的最右侧一定是最大的数 例如65535 或者     INT_MAX 它们作为无穷大

INT_MAX 的引入需要 #include<stdlib.h>

这里的快排分为了两个功能区
```
//Partition
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
```

```
// QuickSort
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
```

```
//Test demo
int main()
{
		int Q[] = { 3,7,9,10,6,5,12,4,11,2,INT_MAX };
	int L = 11; //长度
	QuickSort(Q, 0, 10); 
// 0 是数组的最左边  10是数组的最右边
	Display(Q,11); //11也是可以改成10的
}
	return 0;
```


Merging Sort(合并排序)
1. Two unsorted Array Merging into a sorted Array.
![[Pasted image 20241010125344.png]]


![[Pasted image 20241010125726.png]]
右边的两个数组合并 函数

![[Pasted image 20241010130042.png]]
现在右边的函数 是针对 一个数组的排序

多个无序数组进行合并
n - way merging(多组合并)

Iterative MergeSort(内部合并排序)
![[Pasted image 20241010132502.png]]

Recusive MergeSort(递归 合并排序)
![[Pasted image 20241010135731.png]]
我们是先从一半来看  
如:一半未排序 ， 那就继续除2  直到排好序的那个。

当一个组里只有一个元素时，我们是默认它是已经排好序了的。

![[Pasted image 20241010140803.png]]
我们可以看到，递归合并排序 它是先这个大的数组 不断的 2倍 2倍的缩小。然后直到 一个组里只有 1个元素(Sorted 我们认为它是已经排好序了的).

随后将排好序的数组 递归返回给上一个组里再次进行排序  第一个MergeSort是左子树先排左边 然后在第二个MergeSort排右边 
Merge()是实现排序用的 上一节已经实现了
按照高度来看 是 一个高度里面要处理 n个元素 
O(nlogn)

Count Sort (计数排序)
最快的排序，但是消耗大量内存
![[Pasted image 20241010144925.png]]

![[Pasted image 20241010145518.png]]


Bucket / Bin Sort(桶排序)
![[Pasted image 20241010154841.png]]

![[Pasted image 20241010155023.png]]
liner time O(n)
空间消耗是 O(n)

![[Pasted image 20241010155532.png]]Bins 是结构体数组
个人认为其和Count Sort 的原理大致相同。


Radix Sort(词性排序)
以 整型元素的每个位权 数字填入对应 的 下标内进行排序\

从个位开始，分别取它们个位对应的数，按照顺序依次排序，个位相同的连接到，上一个数的下面。

然后从左到右依次取出，排好序。然后以此次序 从十位开始重复上次操作 。 直到需要排序的最大位权的数 位权排好....

![[Pasted image 20241010160839.png]]
排序的次数 取决于你拥有的最大的数
O(dn)---> O(n)

Shell Sort(希尔排序)\
![[Pasted image 20241010174155.png]]
O(nlogn


### 1. Bin/Bucket Sort

**思想**:

- 将数组元素根据范围放入不同的桶（bin）中。
- 对每个桶内的元素进行排序，然后将它们合并成一个排序好的数组。

**步骤**:

1. 找到数组中的最大值，确定桶的范围。
2. 创建多个桶。
3. 遍历输入数组，将每个元素放入相应的桶中。
4. 对每个桶中的元素进行排序。
5. 将所有桶中排序好的元素合并为一个数组。

### 2. Radix Sort

**思想**:

- 基数排序是基于“分配”和“收集”的方法进行的排序。它从最低有效位开始逐位对数组进行排序，直到最高有效位。
- 采用**计数排序**作为子步骤处理每个位数的排序。

**步骤**:

1. 找到数组中的最大数，确定需要多少位（即进行多少轮排序）。
2. 按照每一位（从最低位到最高位）对数组进行排序。
3. 使用计数排序来实现每一位的排序。

- **桶排序** 适用于范围较小且分布均匀的数组。
- **基数排序** 适用于整数数组，尤其是当数组的数字长度相似时。