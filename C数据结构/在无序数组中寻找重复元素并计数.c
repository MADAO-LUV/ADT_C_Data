#include <stdio.h>
/*
Find Duplicate Elements in unorder Array
在无序数组中寻找重复元素

Way 1: 使用双指针  O(n^2)

Way 2: 使用HashTable  O(n)

*/



void Find_Duplicate(int A[],int n)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		count = 1; //先计数一次

		if (A[i] != -1)  //这里先判断 i处元素不为-1
		{
			for (int j = i + 1; j < n; j++)
			{
				if (A[i] == A[j])  //发现相同元素时
				{
					count++;
					A[j] = -1;
				}
			}

			if (count > 1)printf(" %d %d \n", A[i], count);
		}
	}


}



int main()
{
	int A[10] = { 3,7,1,9,6,3,7,2,2,8 };
	Find_Duplicate(A, 10);

	return 0;
}