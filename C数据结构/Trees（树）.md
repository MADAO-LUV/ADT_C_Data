![[Pasted image 20240925193135.png]]
Terminology：
1.Root 根
2.Parent 父节点
3.child  子节点
4.siblings 兄弟节点
5.Descendents 后代
6.Ancestors 祖先
7.Degree of a ndoe
节点的度 --- 结点拥有的子树个数称为结点的度


8.Intend/External node
9.Levels 层级
10.Height 高度 （树高） 
11.Forest 森林

Height = levels - 1
![[Pasted image 20240925194139.png]]
如图所属 里面是多个树


Binary tree(二分树)
Left skewd tree（左倾树）
Right skewd tree（右倾树）
![[Pasted image 20240925194750.png]]
对于 二分树(二叉树) 来说，
Agree of Nodes  T(n)=2
{0,1,2} 它的 节点的度 不能超过2 不能小于0.

Number of Binary Trees
1.Unlabelled Nodes
无标签的结点

2.Labelled Nodes
有标签的结点
![[Pasted image 20240925195503.png]]、
由这里结点数可以推出
T(3)=5  三个结点 可以 演变出 5个 不同的 二分树类型。 5个镜像

![[Pasted image 20240925195754.png]]
给出 结点数 以及 Catalan Number 卡塔兰数
![[Pasted image 20240925195950.png]]

在这个agree of nodes 中最大高度树的数量
计算为 2^n  数量为 2的n 次方  且 n 为 一个树中的所有结点数量

![[Pasted image 20240925200550.png]]
计算镜像树的数量的两个公式 这个是 没有填入标签的 结点的 镜像树 的 数量计算

![[Pasted image 20240925200747.png]]
如果填入了后 ，还需要在unlabelled nodes 的数量计算 基础上 再乘以 n！ n的阶乘    以返回出  带标签的 labelled nodes 

![[Pasted image 20240925201446.png]]
 高度 vs 结点
 当二叉树的高度相同时
 min Noes : n = h + 1
max Nodes: n = 2^(h+1) - 1
这个是 高度 已经被 告知了。上面的

如果 结点被给出了。
![[Pasted image 20240925202627.png]]
max height  h=n-1
![[Pasted image 20240925203004.png]]


![[Pasted image 20240925205839.png]]
没有子结点的 结点个数
deg(0) = deg(2) + 1
deg(2): 是 有两个子结点的结点个数。


strict Binary Tree

1.Strict/Proper/Complete
(1.严格/正确/完整)
2.Height vs Nodes
3.Internal vs Extend Nodes
(3.内部节点与扩展节点)

规则：1. 一个结点要么没有结点 要么有两个结点
{0,2}
![[Pasted image 20240925210643.png]]
if Height 'h' is gieven
(当高度被告知)

Min Nodes: n = 2h + 1
Max Nodes: n = 2^(h+1)-1
![[Pasted image 20240925210958.png]]
该公式 是 交叉 互通的

在严格二叉树中
Internal vs External Nodes

E 为 外部结点个数
I 为 内部结点个数
e = i + 1

n-ary Trees(n 叉树)
1.what are n-ary Trees
2.strict n-ary Trees
3.Height vs Node
4.Internal vs External Nodes