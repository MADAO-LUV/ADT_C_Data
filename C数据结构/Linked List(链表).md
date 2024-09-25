
![[Pasted image 20240916110302.png]]


```
struct Node
{
	int data;
	struct Node *next;
}
```

检测 p 是否为 空指针
```
if(p==NULL)
if(p==0)
if(!p)
```



递归调用显示
![[Pasted image 20240916115327.png]]
不断递归调用 类似一颗深度搜索树
代码部分:
```
//递归调用 显示所有数据
void RDisplay(struct Node* p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		RDisplay(p->next);
	}

	/*
	另一种写法
	if(p != NULL)
	{
		RDisplay(p->next);
		printf("%d ",p->data);
	}  //倒置显示数据
	*/
}
```


计算链表的长度


寻找链表中最大的值
先用 最小的值 赋予给 max 后面不断比较

搜索链表中对应的值
只能线性搜索 ，因为链表不是随机存取结构
1.
```
// 循环遍历
Node *Search(Node *p,int key)
{
	while(p != NULL)
	{
		if(key==p->data)
			return p;
		p=p->next;
	}
	return NULL; //没有找到的话 返回为空
}

struct Node* RSearch(struct Node* p, int key)
{
	if (p == NULL)
	{
		return NULL;
	}
	if (key == p->data)
	{
		return p;
	}
	return RSearch(p->next, key);
	
}

```

![[Pasted image 20240917235319.png]]

```
//修改版 Linear Search
//将这次寻找到的结点 放到最前面 方便下次再次查询
struct Node* LSearch_demo(struct Node* p, int key)
{
	struct Node* q;
	while (p != NULL)
	{
		if (key == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}
```

插入新的结点
分为两个情况 ： 1.Insert before First
				2.Insertinig after given Position


1.Delete first Node(删除第一个结点)
2.Delete a Node of given Position(给定一个地址删除对应的结点)
```
int Delete(struct Node* p, int index)
{
	struct Node* q;
	int x = -1;

	if (index<1 || index >CountNode(p))
	{
		return -1;
	}
	if (index == 1) //如果在头部时
	{
		q = first;
		x = first->data;
		first = first->next;
		delete q;
		return x;
	}
	else    //不在头部处删除
	{
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}

}
```

检查链表是否排序
```
int isSorted(struct Node* p)
{
	int x = INT_MIN;

	while (p != NULL)
	{
		if (p->data < x)
		{
			return 0;
		}
		x = p->data;
		p = p->next;
	}
	return 1;
}
```

Cirucal Linked List(循环链表)
![[Pasted image 20240919084333.png]]


递归调用 显示
![[Pasted image 20240919091514.png]]
```
void RDisplay(struct Node* h)
{
	static int flag = 0;
	if (h != Head || flag == 0)
	{
		flag = 1;
		printf("%d ", h->data);
		RDisplay(h->next);
	}
	flag = 0;
}
//因为我们设置的为 静态变量flag 所以在递归
//中 flag=1 但是 h 不是头指针 所以一调//用到 Head时 才结束
```


对于循环链表的删除中
![[Pasted image 20240919095105.png]]
对于头结点删除有两种情况
1. 只有头结点一个元素
2. 头结点和其他元素
后面的else 就是 删除 其他位置上的结点


双端链表
![[Pasted image 20240919120443.png]]
插入结点