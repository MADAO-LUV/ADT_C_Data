
// 建立 队列头文件
#ifndef Queue_H
#define Queue_H
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* lchild; //左孩子
	int data;
	struct Node* rchild; //右孩子
};



//定义 队列 结构体
struct Queue
{
	int size;
	int front;
	int rear;
	Node **Q; //结构体数组指针  里面存放结构体Node的地址
};

void Create(struct Queue* q, int size)
{
	q->size = size;
	q->front = q->rear = -1;
	q->Q = (Node **)malloc(q->size * sizeof(Node *));
}

//入队操作
void Enqueue(struct	Queue* q, Node* x)
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
Node * dequeue(struct Queue* q)
{
	Node* x = NULL;

	if (q->front == q->rear)
		printf("Queue is Empty\n");
	else
	{
		q->front++;
		x = q->Q[q->front];
	}
	return x;
}


int isEmpty(struct Queue q)
{
	return q.front == q.rear;
}



#endif // !Queue_H

