#include <stdio.h>
#include <stdlib.h>
//定义 队列 结构体
struct Queue
{
	int size;
	int front;
	int rear;
	int* Q; //整形指针
};

void Create(struct Queue* q, int size)
{
	q->size = size;
	q->front = q->rear = -1;
	q->Q = (int*)malloc(q->size * sizeof(int));
}

//入队操作
void Enqueue(struct	Queue *q,int x)
{
	//判断是否满队
	if (q->front == q->size - 1)
	{
		printf("Queue is Full\n");
		return;
	}
	else
	{
		q->rear++;
		q->Q[q->rear] = x;
	}

}

//出队
int dequeue(struct Queue* q)
{
	int x = -1;

	if (q->front == q->rear)
		printf("Queue is Empty\n");
	else
	{
		q->front++;
		x = q->Q[q->front];
	}
	return x;
}


void Display(struct Queue q)
{
	//这里的q.front+1 是因为 q.front 初始化为-1
	for (int i = q.front+1; i <= q.rear; i++)
	{
		printf("%d ", q.Q[i]);
	}
	printf("\n");

}



int main()
{
	struct Queue q;
	Create(&q, 5);

	for (int i = 0; i < 5; i++)
	{
		Enqueue(&q, i);
	}
	Display(q);

	return 0;
}