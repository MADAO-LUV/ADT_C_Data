#include <stdio.h>
/*
寻找一对和为 k值并且记录他们
*/
#define MAX 20   //自行更改
int HashTable[MAX] = { 0 };

//这里的n是A[]的大小 目标值 k
void Find_SumK(int A[], int H[], int n,int k)
{
	for (int i = 0; i < n; i++)
	{
		if (H[k - A[i]] != 0)
		{
			printf("%d + %d = %d\n", A[i], k - A[i], k);
		}
		H[A[i]]++;
	}
}


int main()
{
	int A[10] = { 6,3,8,10,16,7,5,2,9,4 };
	Find_SumK(A, HashTable, 10, 10);

	return 0;
}