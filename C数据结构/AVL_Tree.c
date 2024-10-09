#include <stdio.h>
#include <stdlib.h>
struct Node
{
	struct Node* lchild;
	int data;
	int high;  //用来记录单个节点的高度
	struct Node* rchild;
}*root=NULL;

// 节点高度 函数
int NodeHeight(struct Node* p)
{
	int hl, hr; //用来记录该节点的左右子树的高度
	hl = p && p->lchild ? p->lchild->high : 0;
	hr = p && p->rchild ? p->rchild->high : 0;

	return hl > hr ? hl + 1 : hr + 1;
	// p的高度是更高的决定
}


int BalanceFactor(struct Node* p)
{
	int hl, hr;
	// p && p->lchild 这里是 先判断 节点p是否存在 ，然后取 p的子节点的高度
	hl = p && p->lchild ? p->lchild->high : 0; // 节点p 如果存在右字树，那么hr就为右子树的高度
	hr = p && p->rchild ? p->rchild->high : 0;

	return hl - hr;
}


//这里是 左左旋转
/*
解释：1.pl 是 传入的节点 的左字节点
2.plr  是 传入的节点 的左字节点的 右子节点。 它后面是要到 p的左子节点处

最好是结合 笔记里的 图示来看这个
*/
struct Node* LLRotation(struct Node* p)
{
	struct Node* pl = p->lchild;
	struct Node* plr = pl->rchild;

	pl->rchild = p; //因为进行了 LL旋转， 这个节点p 成为了 pl 的右字节点
	p->lchild = plr; //这里就成为了传入节点的 左子节点
	p->high = NodeHeight(p); //更新该节点的高度
	pl->high = NodeHeight(pl);

	if (root == p)
	{
		root = pl; //pl成为新的节点
	}

	return pl; //把pl作为新的节点p返回 
	//谁成为中间那个 就返回谁
}


struct Node* LRRotation(struct Node* p)
{
	struct Node* pl = p->lchild;
	struct Node* plr = pl->rchild;

	pl->rchild = plr->lchild; //这里根据大小判断 放的，左小 右大
	p->lchild = plr->rchild;

	plr->lchild = pl;
	plr->rchild = p;

	pl->high = NodeHeight(pl);
	plr->high = NodeHeight(plr);
	p->high = NodeHeight(p);

	if (root == p)
	{
		root = plr;
	}

	return plr;
}


struct Node* RRRotation(struct Node* p)
{
	struct Node* pr = p->rchild;
	struct Node* prl = pr->lchild; //设置 三个指针。

	p->lchild = prl;
	pr->lchild = p;  //进行交换了

	p->high = NodeHeight(p);
	pr->high = NodeHeight(pr); //因为 pr的左子节点的高度不改变

	if (root = p)
	{
		root = pr;
	}
	return pr;

}

/**
前提提要: 左小 右大
节点p < 节点 prl < 节点pr 

那么 prl -> lchild > p && prl -> lchild < pr; 所以 这个应该去到 p 的rchild 应该是刚好缺少 rchild
      p->rchild = prl->lchild;
那么 prl->rchild 虽然是 大于 prl 但是 它仍然小于 pr 因为 prl是 pr的左子节点  因为prl去到了中间位置 pr的左子节点刚好空出
      那么就有 pr->lchild = prl->rchild;

**/
struct Node* RLRotation(struct Node* p)
{
	struct Node* pr = p->rchild; //这里是 节点p的右子节点
	struct Node* prl = pr->lchild; // 这个是 pr的左子节点

	pr->lchild = prl->rchild;
	p->rchild = prl->lchild;  //还是根据 那个左小 右大

	prl->lchild = p;
	prl->rchild = pr;

	pr->high = NodeHeight(pr);
	prl->high = NodeHeight(prl);
	p->high = NodeHeight(p);

	if (root == p)
	{
		root = prl;
	}
	return prl;
}

struct Node* RInsert(struct Node* p, int key)
{
	struct Node* t = NULL;

	if (p == NULL)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = key;
		t->high = 1;
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

	p->high = NodeHeight(p); //每增加一个新节点，需要对所属节点的高度进行更新

	//这里是 根据 平衡因素 来进行相应的旋转。
	if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
	{
		return LLRotation(p);
	}
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) ==  -1)
	{
		return LRRotation(p);
	}
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
	{
		return RRRotation(p);
	}
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
	{
		return RLRotation(p);
	}

	return p;

}

//前序遍历函数
void PreOrder(struct Node* p)
{
	if (p)
	{
		printf("%d ", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void Inorder(struct Node* p)
{
	if (p)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}

//删除结点
struct Node* RDelete(struct Node* p, int key)
{
	if (p == NULL)return p;  //这个结点 没有被找到

	//标记 结点 以便删除
	if (key < p->data)
	{
		p->lchild = RDelete(p->lchild, key);//继续搜素
	}
	else if (key > p->data)
	{
		p->rchild = RDelete(p->rchild, key);
	}
	else //这个就是找到了目标结点
	{
		struct Node* temp; //创建临时 结点
		if (p->lchild == NULL || p->rchild == NULL)
		{
			temp = p->lchild ? p->lchild : p->rchild; 
			//如果p->lchild存在 就是指定p->lchild否则就为p->rchild
			free(p);
			return temp; //返回不为NULL的子节点
		}
		else
		{
	//有两个子节点的节点： 获取顺次继承节点（右侧子树中最小的节点）
			struct Node* successor = p->rchild;
			while (successor && successor->lchild)
			{
				successor = successor->lchild;
			}
			p->data = successor->data; //复制successor里的值
			p->rchild = RDelete(p->rchild, successor->data); //删除successor

		}

	}

	//更新结点高度
	p->high = NodeHeight(p);

	//让树重新变得平衡
	//这里是左旋转
	if (BalanceFactor(p) == 2)
	{
		if (BalanceFactor(p->lchild) >= 0)
		{
			return LLRotation(p);
		}
		else
		{
			return LRRotation(p);
		}
	}

	//这里是右旋转
	if (BalanceFactor(p) == -2)
	{
		if (BalanceFactor(p->rchild) <= 0)
		{
			return RRRotation(p);
		}
		else
		{
			return RLRotation(p);
		}
	}

	return p; //返回最新的结点 （经历过删除操作的剩余结点）
}




int main()
{
	//注意 代码在插入时， 不要 极差过大 会报错的。,而且不要太偏向一遍
	root = RInsert(root, 45);
	RInsert(root, 30);
	RInsert(root, 33);
	RInsert(root, 40);
	RInsert(root, 50);
	RInsert(root, 27);

	//代码无误 根据 严密计算 步骤正确
	PreOrder(root);
	printf("\n");
	Inorder(root);

	return 0;
}