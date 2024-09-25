#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
}*front = NULL, * rear = NULL;


void Enqueue(int x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));

	//判断是否满队
	if (t == NULL)
	{
		printf("Queue is FULL\n");
	}
	else
	{
		t->data = x;
		t->next = NULL;
		if (front == NULL)
		{
			front = rear = t;
//头指针 尾指针 指向同一个结点 头结点
		}
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int Dequeue()
{
	int x = -1;
	struct Node* t;

	//判断是否为空队
	if (front == NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		x = front->data;
		t = front;
		front = front->next;
		free(t); //释放内存
	}
	return x;
}


void Display()
{
	struct Node* p = front;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

}



int main()
{
	
	Enqueue(50);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	Enqueue(10);
	Enqueue(90);

	Display();
	return 0;
}