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
	q->front = q->rear = 0;
	q->Q = (int*)malloc(q->size * sizeof(int));
}

//入队操作
//这里是 头指针 所指的那个空间 是空出来的
void Enqueue(struct	Queue* q, int x)
{
	//因为是循环队列 所以这里判断是否满队
	//是看(q->rear+1)%size 它的下标是否与 q->front 相等
	if ((q->rear+1)%q->size == q->front)
	{
		printf("Queue is Full\n");
		return;
	}
	else
	{
		q->rear=(q->rear+1)%q->size;
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
		q->front=(q->front+1)%q->size;
		x = q->Q[q->front];
	}
	return x;
}


void Display(struct Queue q)
{
	int i = q.front + 1;

	do {
		printf("%d ", q.Q[i]);
		i = (i + 1) % q.size;
	} while (i != (q.rear + 1) % q.size); 
	//防止 i 遍历越界

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