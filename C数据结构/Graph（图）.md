![[Pasted image 20241011092139.png]]Directed Acyclic Graph(有向循环图)---DAG

![[Pasted image 20241011093036.png]]

通过临接矩阵 来表示 图的里的成本
![[Pasted image 20241011093303.png]]


![[Pasted image 20241011093441.png]]
我们看到这里 v 是 图中元素的个数
e 是 边的个数  

|v|+2|E|+1=21 是为了计算出 compact List 的大小

![[Pasted image 20241011094144.png]]
This is directed Graph
所用的数据结构不同，搜寻的时间不同.


Breadth First Search(BFS)
广度优先搜索.

![[Pasted image 20241011094854.png]]
虚线代表，再一次遍历(重复遍历)
BFS的遍历顺序不是不变的，可以有多种形式

画出树图，再用层级遍历
![[Pasted image 20241011095532.png]]


![[Pasted image 20241011095752.png]]
Spanning Tree --- 扩展树
Cross Edges --- 交叉边

![[Pasted image 20241011100133.png]]
q 表示的访问过的节点已入队
visited 表示已经访问过的节点

![[Pasted image 20241011100628.png]]
时间复杂度为O(n^2) 
广度优先搜索 用到队列。


DFS(Depth First Search)深度优先搜索
深度优先搜索 用到栈
![[Pasted image 20241011102848.png]]
虚线是 --- back edge 回溯边缘
DFS Spanning Tree

![[Pasted image 20241011103822.png]]

Spanning Tree:
1.spanning Tree
2.Prims MST
3.Kruskals MST

![[Pasted image 20241011113946.png]]
生成树不止一个
![[Pasted image 20241011114232.png]]
通过这个些树，我们对它们的路径进行统计 可以找到花费成本最小的那个Spanning Tree 
也有别的尝试 成本提供
![[Pasted image 20241011114900.png]]
Prim's Minimum Cost Spanning tree
![[Pasted image 20241011143018.png]]
成本邻接矩阵
那些划横线的是 代表着最大值

查找特定部分就可以确定 cost的值

框框内标着0的就是已经放进了，不要再次选择


Kruskal 
确保我们连成的图不能形成一个Circular 循环
![[Pasted image 20241011151059.png]]
最终的Cost=60

可以使用最小堆 来实现 找到最小值Cost
![[Pasted image 20241011153754.png]]
完结。