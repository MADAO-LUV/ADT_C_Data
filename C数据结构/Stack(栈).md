![[Pasted image 20240920085709.png]]
```
struct stack
{
	int size;
	int Top;
	int *s;
}

// 判断是否为空
if(top==-1)

//判断是否为满
if(top==size-1)
```

使用链表来实现 栈
```
struct Node
{
	int data;
	struct Node *next;
};

if(Top==NULL)

if(t==NULL)
```

```
int isFull()
{
	Node *t=new Node;
	int r=t? 1:0;  //这里是判断t是否被分配空间
	//如果t==NULL 就说明满栈了 所以释放了
	free(t);
	return r;
}
```

对这个满栈的思考，这里 是靠Node *t = new Node;来进行 满栈判断 那么 就是说 当我们的电脑的内存控制不能再为一个新的结点分配一个栈空间 时。

那么t = NULL; 那么是不是就可以说 此时已经满栈了


现实所需用到 栈(stack)来解决的问题;
1.paranthesis matching （括号匹配）

![[Pasted image 20240920112551.png]]

用Array 来模拟 栈
```
struct Stack
{
	int size;
	int top;
	char *S;
}
```