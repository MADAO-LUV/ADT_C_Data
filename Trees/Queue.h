
// ���� ����ͷ�ļ�
#ifndef Queue_H
#define Queue_H
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* lchild; //����
	int data;
	struct Node* rchild; //�Һ���
};



//���� ���� �ṹ��
struct Queue
{
	int size;
	int front;
	int rear;
	Node **Q; //�ṹ������ָ��  �����Žṹ��Node�ĵ�ַ
};

void Create(struct Queue* q, int size)
{
	q->size = size;
	q->front = q->rear = -1;
	q->Q = (Node **)malloc(q->size * sizeof(Node *));
}

//��Ӳ���
void Enqueue(struct	Queue* q, Node* x)
{
	//�ж��Ƿ�����
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

//����
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

