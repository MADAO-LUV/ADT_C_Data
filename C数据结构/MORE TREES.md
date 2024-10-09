Iterative Tree Traversals
迭代树遍历  或者 树的迭代遍历。
![[Pasted image 20240927091300.png]]
通过栈来存储遍历时，那些节点的地址，需要用到的时候在弹出

当现在的节点为空时，弹出栈顶元素，并且 此时的指针指向 弹出节点的 右孩子。

3.后序遍历
![[Pasted image 20240927093600.png]]



Can we generate Trees from Traverals ?

![[Pasted image 20240927100506.png]]

需要我们 按顺序取下所有元素 按照规范按顺序排列 不要更改顺序元素。

![[Pasted image 20240927101125.png]]
Generating Tree from Traversals 

Preorder --- 
Inorder --- 它们一起确定一个唯一的树 

计算 节点个数
![[Pasted image 20240927103359.png]]

![[Pasted image 20240927103827.png]]
我们使用递归遍历 来统计 Nodes 的个数 其实就是利用了树的结构。
 空间局部性强


计算 叶子节点的个数 ，计算度不同的 节点的个数
![[Pasted image 20240927105435.png]]

4.计算节点的度为1的个数
![[Pasted image 20240927105757.png]]
可以通过异或来减少计算
```
1.#统计 叶子节点
if(!p->lchild && !p->rchild)

2.#统计 非叶子节点
if(p->lchild || p->rchild)

3.统计度为2的节点
if(p->lchild && p->rchild)

4.统计度为1的节点数
if((p->lchild && !p->rchild) || (!p->lchild && p->rchild))

也可以为
if(p->lchild!=NULL ^ p->rchild!=NULL)
```