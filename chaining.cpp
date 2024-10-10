#include<stdio.h>
#include<stdlib.h>
#include"Chains.h"
//实现链式 散列表...
//接在 hash表的后面连接起来             
int hash(int key)
{
	return key % 10; //返回模
}


void MYInsert(struct Node* H[], int key)
{
	int index = hash(key);
	SortedInsert(&H[index], key);
}

int main()
{
	struct Node* HT[10];
	struct Node* temp;
	int i;

	for (i = 0; i < 10; i++)
	{
		HT[i] = NULL;
	}

	MYInsert(HT, 12);
	MYInsert(HT, 22);
	MYInsert(HT, 43);

	temp = LSearch(HT[hash(43)], 43);
	printf("%d ", temp->data);
	return 0;
}