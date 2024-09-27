#include "Queue.h"
#ifndef Stack_h
#define Stack_h

/*
ʹ�� ����Array ����Ϊ ջ
*/
struct Stack
{
	int size;
	int top;
	struct Node **S;
};

void STACKcreate(struct Stack* st,int size)
{
	st->size = size;
	st->top = -1;
	st->S = (struct Node **)malloc(sizeof(struct Node *) * st->size);
}

void Display(struct Stack st)
{
	for (int i = st.top; i >= 0; i--)
	{
		printf("%d ", st.S[i]);
	}
	printf("\n");

}


void pushST(struct Stack* st, struct Node *x)
{
	if (st->top == st->size - 1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		st->top++;
		st->S[st->top] = x;
	}

}

//����Ԫ�� ���Ϊ��ջ �ͷ���-1
struct Node *popST(struct Stack* st)
{
	struct Node* x = NULL;

	if (st->top == -1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		x = st->S[st->top--];
	}
	return x;
}


int IsEmptyStack(struct Stack st)
{
	if (st.top == -1)
	{
		return 1;
	}
	return 0;
}


int IsFullStack(struct Stack st)
{
	return st.top == st.size - 1;
}



#endif // !Stack_h
