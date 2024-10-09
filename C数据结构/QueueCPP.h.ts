#pragma once
#include <stdio.h>
#ifndef Queue_H
#define Queue_H

class Node
{
public:
	Node* lchild;
	int data;
	Node* rchild;
};



//这里我自己改为泛式编程

class Queue
{
private:
	int front;
	int rear;
	int size;
	Node** Q;

public:
	Queue() { front = rear = -1; size = 10; Q = new Node * [size]; }
	Queue(int size) { front = rear = -1; this->size = size; Q = new Node * [this->size]; }
	void Enqueue(Node* x);
	Node* Dequeue();
	int IsEmpty() { return front == rear; }
};


void Queue::Enqueue(Node* x)
{
	if (rear == size - 1)
	{
		printf("Queue is FULL\n");
		return;
	}
	else
	{
		rear++;
		Q[rear] = x; //进队操作
	}

}


Node* Queue::Dequeue()
{
	Node* x = NULL;
	//判断是否为空队
	if (front == rear)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		x = Q[front + 1];
		front++;
	}
	return x;
}


#endif // !QUEUECPP_H
