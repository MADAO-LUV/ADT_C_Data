1. No Duplicate(没有重复)
2. Index gets Sorted Order(搜索时是排好序的)
![[Pasted image 20240929084233.png]]

1.RSearch(Node *t,int key)

尾递归法
```
Node *Rsearch(Node *t,int key)
{
	if(t==NULL)
		return NULL;
	if(t->data==Key)
		return t;
	else if(t->data<key)
		return Rsearch(t->rchild,key);
	else
		return Rsearch(t->lchcild);
}

}



```
![[Pasted image 20240929085744.png]]

尾递归法插入
![[Pasted image 20240929090320.png]]
我们可以发现 
这里的 值判断处时 那个 
p->rchild = insert(p->rchild,key);
这里 insert会返回 节点指针类型。 
所以 如果当p==NULL
的时候 它已经被上一个节点 指向了。   
所以在p == NULL 时 就 可以直接创建节点就好了


![[Pasted image 20240929090807.png]]
所以时间 复杂度为 nlogn

![[Pasted image 20240929094406.png]]
删除

Generating BST from Preorder
![[Pasted image 20240929152713.png]]

我们既可以使用前序遍历 也可以使用后序遍历

DrawBack of Binary Search Tree
![[Pasted image 20240929153024.png]]

树的高度取决于插入时的顺序，如果是顺序插入。那么我们后续的搜索 是O(n)