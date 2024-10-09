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