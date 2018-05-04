#include <stdio.h>
#include <malloc.h>
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
void DispLeaf(BTNode *b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL&&b->rchild == NULL)
			printf("%c ", b->data);
		else
		{
			DispLeaf(b->lchild);
			DispLeaf(b->rchild);
		}

	}
}
void AllPath1(BTNode *b, ElemType path[], int pathlen)
{
	int i;
	if (b != NULL)
	{
		if (b->lchild == NULL&&b->rchild == NULL)
		{
			printf("   %c到根节点逆路径: %c ", b->data, b->data); //先输出叶子结点
			for (i = pathlen - 1; i >= 0; i--)
				printf("%c ", path[i]);     //栈中的节点出栈
			printf("\n");

		}
		else
		{
			path[pathlen] = b->data;     //从根节点到叶子结点先入栈
			pathlen++;               
			AllPath1(b->lchild, path, pathlen);
			AllPath1(b->rchild, path, pathlen);
			pathlen--;;
		}
	}
}

int main()
{
	BTNode *b;
	ElemType path[MaxSize], longpath[MaxSize];
	int i, longpathlen = 0;
	CreateBTNode(b, "A(B(D,E),C(F(H,I),G))");
	printf("二叉树b:\n");
	DispBTNode(b);
	printf("\n");
	printf("叶子结点：");
	DispLeaf(b);
	printf("\n");
	printf("allpath1:\n");
	AllPath1(b, path, 0);
}