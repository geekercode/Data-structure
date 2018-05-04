#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;
void CreateBTNode(BTNode *&b, char *str)		//由str串创建二叉链
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0')	//str未扫描完时循环
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//为左节点
		case ')':top--; break;
		case ',':k = 2; break;                      	//为右节点
		default:p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    //p指向二叉树的根节点
				b = p;
			else  							//已建立二叉树根节点
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
void DispBTNode(BTNode *b)	//以括号表示法输出二叉树
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTNode(b->lchild);
			if (b->rchild != NULL) printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}
void PreOrder(BTNode *b)  //先序遍历的递归算法
{
	if (b != NULL)
	{
		printf("%c ", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
void InOrder(BTNode *b) //中序遍历递归算法
{
	if (b != NULL)
	{
		InOrder(b->lchild);
		printf("%c ", b->data);
		InOrder(b->rchild);

	}
}
void InOrder1(BTNode *b)
{
	BTNode *St[MaxSize], *p;
	int top = -1;
	if (b != NULL)
	{
		p = b;
		while (top > -1 || p != NULL)
		{
			while (p != NULL)  //扫描*p所有的左结点并进栈
			{
				top++;
				St[top] = p;
				p = p->lchild;
			}

			if (top > -1)
			{
				p = St[top]; //出栈p结点
				top--;
				printf("%c ", p->data); //访问之
				p = p->rchild; //转向处理*p的右孩子节点
			}
		}
		printf("\n");
	}
	
}
void PostOrder(BTNode *b)
{
	if (b != NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ", b->data);
	}
}
void TraverseLevel(BTNode *b)
{
	BTNode *Qu[MaxSize];
	int front, rear;
	front = rear = 0;   //定义一个队列
	if (b != NULL)
		printf("%c ", b->data);
	rear++;
	Qu[rear] = b;
	while (rear != front)
	{
		front = (front + 1) % MaxSize;
		b = Qu[front];
		if (b->lchild != NULL)
		{
			printf("%c ", b->lchild->data);
			rear = (rear + 1) % MaxSize;
			Qu[rear] = b->lchild;
		}
		if (b->rchild != NULL)
		{
			printf("%c ", b->rchild->data);
			rear = (rear + 1) % MaxSize;
			Qu[rear] = b->rchild;
  
		}
	}
	printf("\n");
    
}
void main()
{
	BTNode *b;
	CreateBTNode(b, "A(B(D,E),C(F(H,I),G))");
	printf("二叉树的基本运算如下:\n");
	printf("  (1)输出二叉树:"); DispBTNode(b); printf("\n");
	printf("层次遍历算法：");
	TraverseLevel(b);
	printf("先序遍历算法：");
	PreOrder(b);
	printf("\n");
	printf("中序遍历算法：");
	InOrder(b);
	printf("\n");
	printf("中序遍历非递归算法：");
	InOrder1(b);
	printf("\n");
	
}