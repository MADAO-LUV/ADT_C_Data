#include<stdio.h>
#include<stdlib.h>
#include"Chains.h"
//ʵ����ʽ ɢ�б�...
//���� hash��ĺ�����������             
int hash(int key)
{
	return key % 10; //����ģ
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