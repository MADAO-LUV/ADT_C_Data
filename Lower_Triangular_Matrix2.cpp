#include<iostream>
using namespace std;

//下三角矩阵

class LowerTri
{
private:
	int* A;  //用来动态分配内存
	int n; //维度
public:
	LowerTri()
	{
		n = 2;
		A = new int[2*(2+1)/2]; //这个是我们的默认分法
	}
	LowerTri(int n)
	{
		//传入维度 n的值
		this->n = n;
		this->A = new int[n*(n+1)/2];
	}
	void Set(int i, int j, int x);
	void Display();
	int Get(int i, int j);
	~LowerTri()
	{
		delete[]A; //删除所分配的动态空间
	}
};

void LowerTri::Set(int i, int j, int x)
{
	if (i >= j)
		A[i * (i - 1) / 2 + j - 1] = x;
}


int LowerTri::Get(int i, int j)
{
	if (i == j)
	{
		return A[i * (i - 1) / 2 + j - 1]; //返回对角线上的值
	}
	else
	{
		return 0;
	}
}


void LowerTri::Display()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i >= j)
			{
				cout << A[i * (i - 1) / 2 + j - 1] << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}

}int main()
{

	LowerTri d(4);

	d.Set(1, 1, 5);
	d.Set(2, 2, 6);
	d.Set(3, 3, 7);
	d.Set(4, 4, 8);

	cout << endl;
	cout << d.Get(2, 2) << endl;
	d.Display();

	return 0;
}