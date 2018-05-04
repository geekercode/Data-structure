#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char Elemtype;
typedef struct node
{
	Elemtype data;
	struct node *lchild;
	struct node *rchild;

}BTNode;
void CreateBTNode(BTNode *&b, char *str) //str串创建二叉树
{
	BTNode *st[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':top++; st[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch;
			p->rchild = p->lchild = NULL;
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:st[top]->lchild = p;
					break;
				case 2:st[top]->rchild = p;
					break;

				}
			}
		}
		j++;
		ch = str[j];
		
	}
 
}
BTNode *LchildNode(BTNode *p) 
{
	return p->lchild;
}
BTNode *RchildNode(BTNode *p)
{
	return p->rchild;
}
int BTNodeDepth(BTNode *b)  //树的深度求解
{
	int lchilddep, rchilddep;
	if (b == NULL)
		return 0;
	else
	{
		lchilddep = BTNodeDepth(b->lchild);
		rchilddep = BTNodeDepth(b->rchild);
		return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);

	}
}
void DispBTnode(BTNode *b)  //括号表示法输出二叉树
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTnode(b->lchild);
			if (b->rchild != NULL)
				printf(",");
			DispBTnode(b->rchild);
			printf(")");
		}
	}
}
int TotalNode(BTNode *b)  //二叉树的节点个数
{
	int num1, num2;
	if (b == NULL)
		return 0;
	else if (b->lchild == NULL&&b->rchild == NULL)
		return 1;
	else
	{
		num1 = TotalNode(b->lchild);
		num2 = TotalNode(b->rchild);
		return(num1 + num2 + 1);

	}
}
int BTWidth(BTNode *b)
{
	struct 
	{
		int lno;
		BTNode *p;

	}Qu[MaxSize];
	int front, rear;
	int lnum, max, i, n;
	front = rear = 0;
	if (b != NULL)
	{
		rear++;
		Qu[rear].p = b;
		Qu[rear].lno = 1;
		while (rear != front)
		{
			front++;
			b = Qu[front].p;
			lnum = Qu[front].lno;
			if (b->lchild != NULL)
			{
				rear++;
				Qu[rear].p = b->lchild;
				Qu[rear].lno = lnum + 1;
			}
			if (b->rchild != NULL)
			{
				rear++;
				Qu[rear].p = b->rchild;
				Qu[rear].lno = lnum + 1;
			}

		}
		max = 0; lnum = 1; i = 1;
		while (i <= rear)
		{
			n = 0;
			while (i <= rear&&Qu[i].lno == lnum)
			{
				n++;
				i++;
			}
			lnum = Qu[i].lno;
			if (n > max) max = n;

		}
		return max;
	}
	else
		return 0;
}
int Nodes(BTNode *b)
{
	int num1, num2;
	if (b == NULL)
		return 0;
	else if (b->lchild == NULL&&b->rchild == NULL)
		return 1;
	else
	{
		num1 = Nodes(b->lchild);
		num2 = Nodes(b->rchild);
		return num1 + num2 + 1;
	}
}
void main()
{
	BTNode *b, *p, *lp, *rp;
	CreateBTNode(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("二叉树的基本运算如下：\n");
	printf("1,输出二叉树：");
	DispBTnode(b);
	printf("\n");
	printf("2,二叉树的节点个数：%d\n", TotalNode(b));
	printf("宽度是：%d\n", BTWidth(b));
	printf("二叉树的节点个数是：%d\n", Nodes(b));
}