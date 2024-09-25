#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};


class Stack
{
private:
	Node* top;
public:
	Stack() { top = NULL; }
	void push(int x);
	int pop();
	void Display();
};

void Stack::push(int x)
{
	Node* t = new Node;
	if (t == NULL)
		cout << "Stack is Full" << endl;
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}

}

//当 pop()返回的值为-1时 则是空栈
int Stack::pop()
{

	int x = -1;
	if (top == NULL)
	{
		cout << "Stack is Empty\n";
	}
	else
	{
		x = top->data;
		Node* p = top;
		top = top->next;  //栈减小了 栈顶指针往前移动
		delete(p);
	}
	return x;
}

void Stack::Display()
{
	Node* p = new Node;
	p = top;
	while (p != NULL)
	{
		cout << p->data <<" " ;
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Stack stk;
	stk.push(100);
	stk.push(200);
	stk.push(300);

	stk.Display();
	cout << stk.pop();
	stk.Display();
	return 0;
}