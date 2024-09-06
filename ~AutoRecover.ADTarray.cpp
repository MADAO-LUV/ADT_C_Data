#include <iostream>
using namespace std;

template<class T> //泛型编程
class Array
{
private:
	T * A;
	int size;
	int length;

public:
	Array()
	{
		size = 10;
		A = new T[10];
		length = 0;
	}
	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new T[size];
	}
	~Array()
	{
		delete[]A;  //释放内存
	}
	void Display();
	void Insert(int index, T x);
	T Delete(int index);

};

template<class T>
void Array<T>::Display()
{
	for (int i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl; //结束输出
}

template<class T>
void Array<T>::Insert(int index, T x)
{
	if (index >= 0 && index <= length)
	{
		for (int i = length - 1; i > index; i--)
		{
			A[i + 1] = A[i];
		}
		A[index] = x;  //放入数据
		length++;
	}
}

template<class T>
int Array<T>::Delete(int index)
{
	int x=0;
	if (index >= 0 && index < length)
	{
		x = A[index];
		for (int i = index; i < length-1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
	}
	return x;
}


int main()
{
	Array arr(10);

	arr.Insert(0, 5);
	arr.Insert(1, 6);
	arr.Insert(2, 9);
	arr.Display();
	cout << arr.Delete(0) << endl;
	arr.Display();

	return 0;
}