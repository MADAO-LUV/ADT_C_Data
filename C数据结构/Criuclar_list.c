#include <stdio.h>
#include <stdlib.h>


struct Node
{
	int data;
	struct Node* next;
}*Head;


void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	Head = (struct Node*)malloc(sizeof(struct Node));
	Head->data = A[0];
	Head->next = Head;  //先指向自己
	last = Head;

	//把 数据放入 链表中
	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

int Length(struct Node* p)
{
	int len = 0;
	do
	{
		len++;
		p = p->next;
	} while (p != Head);
	return len;
}

void Display(struct Node* h)
{
	//因为是 遍历 先 执行程序内容再判断
	do
	{
		printf("%d ", h->data);
		h = h->next;
	} while (h!=Head);
	printf("\n");
	//如果你放在前面 的话，就不能执行了
}


void RDisplay(struct Node* h)
{
	static int flag = 0;
	if (h != Head || flag == 0)
	{
		flag = 1;
		printf("%d ", h->data);
		RDisplay(h->next);
	}
	flag = 0;
}


void Insert(struct Node* p, int index, int x)
{
	struct Node* t;
	int i;

	if (index<0 || index>Length(Head))
	{
		return;
	}

	//因为是循环链表
	if (index == 0)
	{
		//如果是空链表就 直接插入
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		if (Head == NULL)
		{
			Head = t;
			Head->next = Head;
		}
		//如果不是空链表 得先找到最后边的结点 然后再插入
		else
		{
			while (p->next != Head)p = p->next;
			p->next = t;
			t->next = Head;
			Head = t;
		}

	}

	else
	{
		for (i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}


int Delete(struct Node* p, int index)
{
	struct Node* q;
	int i,x;

	if (index < 0 || index > Length(Head))
	{
		return -1;
	}

	if (index == 1)
	{
		while (p->next != Head)p = p->next;
		x = Head->data;
		//头结点删除部分
		if (Head == p)
		{
			free(Head);
			Head = NULL;
		}
		else
		{
			p->next = Head->next;
			free(Head);
			Head = p->next;
		}

	}
	else
	{
		for (i = 0; i < index - 2; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		x = q->data;
		free(q);
	}
	return x;
}


int main()
{
	int A[] = { 2,3,4,5,6 };
	create(A, 5);

	Insert(Head,0, 9); //插入点 0 
	Delete(Head, 1); //删除第几个结点
	RDisplay(Head);

	return 0;
}