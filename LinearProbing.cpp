#include<stdio.h>
#define SIZE 10

int hash(int key)
{
	return key % SIZE;
}

//用来线性检查 并找出下一个空闲的空间 探针功能 Linear
int probe(int H[],int key)
{
	int index = hash(key); // 获得Hash索引值
	int i = 0;
	while (H[index + i] % SIZE != 0)
		i++;
	return (index + i) % SIZE; //返回最终位置
}


void Insert(int H[], int key)
{
	int index = hash(key);

	if (H[index] != 0) //遇到H[index]里有数值就进行probe
	{
		index = probe(H, key);
	}
	H[index] = key;

}

// 寻找这个键值 的 位置
int Search(int H[], int key)
{
	int index = hash(key);//如果线性查找失败的话

	int i = 0;

	while (H[(index + i) % SIZE] != key)
	{
		i++; //直到在该hash表中寻找到了 键值
	}

	return (index + i) % SIZE;
}

/*-------------------------------------------*/
//这里是Quatric Probe
int Qprobe(int H[], int key)
{
	int index = hash(key);

	int i = 0;
	while (H[(index + i * i)%SIZE] != 0)
	{
		i++;
	}

	return (index + i * i) % SIZE;
}

int QSearch(int H[], int key)
{
	int index = hash(key);

	int i = 0;
	while (H[(index + i * i) % SIZE] != key)
	{
		i++;
	}

	return (index + i * i) % SIZE;
}


void QInsert(int H[], int key)
{
	int index = hash(key);

	if (H[index] != 0)
	{
		index = Qprobe(H, key);

	}
	H[index] = key;
}


int main()
{
	int HT[10] = { 0 };//全都初始化为0
	QInsert(HT, 21);
	QInsert(HT, 12);
	QInsert(HT, 38);

	printf("Key Found at %d\n", QSearch(HT,38));
	return 0;
}

