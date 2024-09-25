#include <stdio.h>
#include <stdlib.h>

/*
使用 数组Array 来作为 栈
*/
struct Stack
{
	int size;
	int top;
	int* S;
};

void create(struct Stack* st)
{
	printf("Enter Size\n");
	scanf_s("%d", &st->size);
	st->top = -1;
	st->S = (int*)malloc(sizeof(int) * st->size);
}

void Display(struct Stack st)
{
	for (int i = st.top; i >= 0; i--)
	{
		printf("%d ", st.S[i]);
	}
	printf("\n");

}


void push(struct Stack* st, int x)
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

//弹出元素 如果为空栈 就返回-1
int pop(struct Stack* st)
{
	int x = -1;

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

//索引为 pos = top - index + 1
int peek(struct Stack st, int index)
{
	int x = -1;
	if (st.top - index + 1 < 0)
	{
		printf("Invalid Index \n");
	}
	x = st.S[st.top - index + 1];

	return x;
}

int IsEmpty(struct Stack st)
{
	if (st.top == -1)
	{
		return 1;
	}
	return 0;
}


int IsFull(struct Stack st)
{
	return st.top == st.size - 1;
}


int stackTop(struct Stack st)
{
	if (!IsEmpty(st))
		return st.S[st.top];
	return -1;
}


int main()
{
	struct Stack st;
	create(&st);

	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);

	printf("%d \n", peek(st,4));

	Display(st);

	return 0;
}