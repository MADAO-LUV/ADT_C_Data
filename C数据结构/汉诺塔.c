#include<stdio.h>

//Hanoi 塔 递归解决 
//时间复杂度为 O(2^n)

/*
@para   n --- 碟片数

A --- from   起始
B --- using  经过点
C --- end    目的地
*/
void Hanoi(int n, int A, int B, int C)
{
	if (n > 0)
	{
		Hanoi(n - 1, A, C, B);
		printf("from %d to %d\n", A, C);
		Hanoi(n - 1, B, A, C);
	}
}