#include <stdio.h>
#include <stdlib.h>
struct Node
{
	struct Node* lchild;
	int data;
	struct Node* rchild;
}*root=NULL;

/*
BST (Binary Search Tree)
二叉搜索树 
1.没有重复
2.在搜索的时候 可以插入节点

*/




//使用循环 （迭代）
void Insert(int key)
{
	struct Node* t = root;
	struct Node* p;
	struct Node* r = NULL;

	if (root == NULL)
	{
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return; //这个return 千万不要忘记
	}
	while (t != NULL)
	{
		r = t;
		if (key < t->data)
		{
			t = t->lchild;
		}
		else if (key > t->data)
		{
			t = t->rchild;
		}
		else
		{
			return; //这里的条件是t->data==key 重复了，结束函数
		}
	}
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;

	if (key < r->data)
	{
		r->lchild = p;
	}
	else
	{
		r->rchild = p;
	}

}

//用来访问 BST
void Inorder(struct Node* p)
{
	if (p)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}

//递归插入
struct Node* RInsert(struct Node *p,int key)
{
	struct Node* t=NULL;
	if (p == NULL)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if (key < p->data)
	{
		p->lchild = RInsert(p->lchild, key);
	}
	else if (key > p->data)
	{
		p->rchild = RInsert(p->rchild, key);
	}
	return p; //返回节点
}

//返回高度
int Height(struct Node* p)
{
	int x, y;
	if (p == NULL)return 0;
	x = Height(p->lchild);
	y = Height(p->rchild);
	return x > y ? x + 1 : y + 1;
}


//返回最右的孩子
struct Node* Inpre(struct Node* p)
{
	while (p && p->rchild != NULL)
	{
		p = p->rchild;
	}
	return p;
}


//返回最左的孩子
struct Node* Insucc(struct Node* p)
{
	while (p && p->lchild != NULL)
	{
		p = p->lchild;
	}
	
	return p;
}

//删除节点
struct Node* Delete(struct Node* p, int key)
{
	struct Node* q = NULL;
	if (p == NULL)
	{
		return NULL;
	}
	if (p->lchild == NULL && p->rchild == NULL)
	{
		if (p == root)
			root = NULL;
		free(p);
		return NULL;
	}



	if (key < p->data)
	{
		p->lchild = Delete(p->lchild,key);
	}
	else if (key > p->data)
	{
		p->rchild = Delete(p->rchild, key);
	}

	else
	{
		//根据 高度判断选择哪个 子树的节点 确保平衡
		if (Height(p->lchild) > Height(p->rchild))
		{
			q = Inpre(p->lchild);   //Inpre是右
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else //当右边子树 高度 大于 左边时
		{
			q = Insucc(p->rchild); //Insucc是左
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}

	}

	return p;
}




//搜素函数
struct Node* Search(int key)
{
	struct Node* t = root;

	while (t != NULL)
	{
		if (key == t->data)
		{
			return t;
		}
		else if (key < t->data)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}
	//如果没有找到
	return NULL;
}



int main()
{
	struct Node* p = NULL;
	root=RInsert(root,10);
	RInsert(root,5);
	RInsert(root,20);
	RInsert(root,8);
	RInsert(root,30);

	Delete(root, 20);
	Inorder(root);
	printf("\n");

	p = Search(20);
	if (p != NULL)
	{
		printf("Yes");
	}
	else
	{
		printf("false");
	}

	return 0;
}