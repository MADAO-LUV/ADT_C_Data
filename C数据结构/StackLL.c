#include <stdio.h>
#include <stdlib.h>
//这里作为全局变量
struct Node
{
	int data;
	struct Node* next;
}*top=NULL;

void push(int x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));

	if (t == NULL)
	{
		printf("Stack is full\n");
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}

}

// Top 是 栈顶指针
int Pop()
{
	struct Node* t;
	int x = -1;

	if (top == NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

//展示 栈中元素
void Display()
{
	struct Node* p;
	p = top;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}



int main()
{
	push(10);
	push(20);
	push(30);

	Display();



	return 0;
}