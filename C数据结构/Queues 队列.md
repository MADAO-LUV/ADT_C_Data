它的性质是先进先出
ADT

Data:
1.Space for storing elements

2.Front-for delete elements

3.Rear-for Insertinon

Operatinos:
1.enqueue(x)
2.dequeue()
3.isEmpty()
4.isFull()
5.first()
6.Last()



Queues using Array
1.Queue using-Single Pointer

2.Queue using-front and Rear

3.Drawbacks of Queue uisng Array

![[Pasted image 20240925095527.png]]
这里是 队列的初始化分析
1.Inititally 初始化 
front=Rear=-1;

2.Empty
if(front==Rear) 这里是判断是否为空

![[Pasted image 20240925100046.png]]
对于 数组式队列的初始化


Circular Queue(循环队列)
解决方案:
1.Reseting Pointers（重置指针）

![[Pasted image 20240925105556.png]]


链表实现队列
![[Pasted image 20240925113020.png]]


双向队列 Dequeue
![[Pasted image 20240925114652.png]]


优先队列 Priority Queues
1.Limited set of priorties
2.Element Priority 

规则是：数字越小，优先级数越小，优先级越大

usingc2 stacks
用两个栈来模拟队列的实现。

![[Pasted image 20240925192404.png]]
这里是，先把数据（data）先放入第一个栈中，根据栈的性质（FILO），然后数据再跑到第二个栈中，再由于第二个栈的（FILO）的性质来实现 队列的FIFO 。 类似于 负负得正。