#include <stdio.h>

/*
 使用HashTable 来记录重复数次数
 @para max 哈希表的最大容量  其大小必须是n+1 才可以模拟 对应的数从而记录重复次数

时间复杂度为 O(n)

*/
#define max 20

int HashTable[max] = { 0 };
int a[10] = { 3,6,8,8,10,12,15,15,15,20 };

void Find_Duplicate(int a[], int H[],int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		H[a[i]]++;
	}

	//这里的i是 对应的数  H[i] 是该数重复的次数
	for (int i = 0; i <= max; i++)
	{
		if (H[i] > 1)
		{
			printf(" %d %d ",i, H[i]);
		}
	}
}

int main()
{

	Find_Duplicate(a, HashTable, 10);


	return 0;
}
