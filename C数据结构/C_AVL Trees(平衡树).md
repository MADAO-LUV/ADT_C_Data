balance factor = height of left subtree - height of right subtree
平衡条件
hl - hr = {-1.0,1} 绝对值 小于等于1

如果 |bf| = |hl-hr| > 1 imbalance 不平衡
![[Pasted image 20240929153956.png]]
这里可以看到 为啥每个节点都有红色标记
那是因为 它们是经过 hl - hr 计算的结果
只有左子树 那么就是 正值  只有右子树 那么就是负值。

Rotation for Insertion 
![[Pasted image 20240929154458.png]]
LL- imbalance 就是左左子树不平衡。 右旋转 使得该树平衡

![[Pasted image 20240929154758.png]]
RR-imbalance Tree 右右不平衡字树 一次左旋转
该树得到平衡

![[Pasted image 20240929155053.png]]
LR-imbalance Tree 左右不平衡树 两次旋转。第一次左旋转 为 LL-imbalance Tree 然后 在进行一次右旋转为 平衡树  AVL-Tree  

那么，RL-imbalance Tree同理。
double rotation

![[Pasted image 20240929185432.png]]


双重旋转的变法
![[Pasted image 20240929185544.png]]

example：
![[Pasted image 20240929185840.png]]


NodeHeight 它是由更高的那个子节点所决定的
![[Pasted image 20240929191242.png]]
```
// 节点高度 函数
int NodeHeight(struct Node* p)
{
	int hl, hr; //用来记录该节点的左右子树的高度
	hl = p && p->lchild ? p->lchild->high : 0;
	hr = p && p->rchild ? p->rchild->high : 0;

	return hl > hr ? hl + 1 : hr + 1;
	// p的高度是更高的决定
}
```

例如：
![[Pasted image 20240930135721.png]]


Rotation for Deletion(因删除结点的旋转)
![[Pasted image 20240930140042.png]]

![[Pasted image 20240930140505.png]]
删除结点 仍然保持平衡 结构


分析Height vs Nodes of AVL Trees
![[Pasted image 20240930163648.png]]
1.最大的Nodes = 2^h  -1
2.最小Nodes 查表
![[Pasted image 20240930163944.png]]
可以发现 max Height 根斐波那契数列的公式有关系