#include<stdio.h>
#include<malloc.h>
#define Maxsize 100
#define MaxWidth 40
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;
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
BTNode *CreateBT1(char *pre, char *in, int n) //pre存放先序序列，in存放中序序列，n为二叉树节点的个数
{
	BTNode *s;
	char *p;
	int k;
	if (n <= 0)
		return NULL;
	s = (BTNode *)malloc(sizeof(BTNode));  //创建二叉树节点*s
	s->data = *pre;
	for (p = in; p < in + n; p++) //在中序序列中找等于*pre的位置k
		if (*p == *pre)           //pre指向根节点
			break;
	k = p - in;					  //确定根节点在in中的位置
	s->lchild = CreateBT1(pre + 1, in, k); //递归构造左子树
	s->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);//递归构造右子树
	return s;
}
void main()
{
	BTNode *b;
	ElemType pre[] = "ABDEHJKLMNCFGI";
	ElemType in[] = "DBJHLKMNEAFCGI";
	
	b = CreateBT1(pre, in, 14);
	printf("先序序列：%s\n", pre);
	printf("中序序列：%s\n", in);
	printf("构造一颗二叉树：\n");
	printf("括号表示法：");
	DispBTNode(b);
	printf("\n");
}