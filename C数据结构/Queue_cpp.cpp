#include <iostream>
using namespace std;

//这里我自己改为泛式编程
template <class T>
class Queue
{
private:
	int front;
	int rear;
	int size;
	T* Q;

public:
	Queue() { front = rear = -1; size = 10; Q = new T[size]; }
	Queue(int size) { front = rear = -1; this->size = size; Q = new int[this->size]; }
	void Enqueue(T x);
	T Dequeue();
	void Display();
};

template <class T>
void Queue<T>::Enqueue(T x)
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

template <class T>
T Queue<T>::Dequeue()
{
	int x = -1;
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

template <class T>
void Queue<T>::Display()
{
	for (int i = front + 1; i <= rear; i++)
	{
		cout << this->Q[i] << " ";
	}
	printf("\n");
}


int main()
{
	Queue<int> q(5);

	for (int i = 1; i < 6; i++)
	{
		q.Enqueue(i);
	}
	q.Display();

	return 0;
}