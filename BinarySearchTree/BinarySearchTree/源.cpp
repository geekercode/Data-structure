#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef int KeyType;
typedef char InfoType;
typedef struct node
{
	KeyType key;
	InfoType data;
	struct node *lchild, *rchild;
}BSTNode;

int path[MaxSize];
void DispBST(BSTNode *b);
int InsertBST(BSTNode *&p, KeyType k)
{
	if (p == NULL)
	{
		p = (BSTNode *)malloc(sizeof(BSTNode));
		p->key = k;
		p->lchild = p->rchild = NULL;
		return 1;
	}
	else if (k == p->key)
		return 0;
	else if (k < p->key)
		return InsertBST(p->lchild, k);
	else
		return InsertBST(p->rchild, k);
}
BSTNode *CreateBST(KeyType A[], int n)
{
	BSTNode *bt = NULL;   //初始化时bt为空树
	int i = 0;
	while(i<n)
		if (InsertBST(bt, A[i]) == 1)
		{
			printf("  第%d步，插入%d：", i + 1, A[i]);
			DispBST(bt);
			printf("\n");
			i++;
		}
	return bt;
}
void DispBST(BSTNode *bt)  //括号表示法输出二叉排序树bt
{
	if (bt != NULL)
	{
		printf("%d", bt->key);
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			printf("(");
			DispBST(bt->lchild);
			if (bt->rchild != NULL)
				printf(",");
			DispBST(bt->rchild);
			printf(")");
		}
	}
}
KeyType predit = -32767;
int JudgeBST(BSTNode *bt)
{
	int b1, b2;
	if (bt == NULL)
		return 1;
	else
	{
		b1 = JudgeBST(bt->lchild);
		if (b1 == 0 || predit >= bt->key)
			return 0;
		predit = bt->key;
	    
		b2 = JudgeBST(bt->rchild);
		return b2;
	}
}
void SearchBST1(BSTNode *bt, KeyType k, KeyType path[], int i)
{
	int j;
	if (bt == NULL)
		return;
	else if (k == bt->key)
	{
		path[i + 1] = bt->key;
		for (j = 0; j <= i + 1; j++)
			printf("%3d", path[j]);
		printf("\n");
	}
	else
	{
		path[i + 1] = bt->key;
		if (k < bt->key)
			SearchBST1(bt->lchild, k, path, i + 1);  //在左子树中查找
		else
			SearchBST1(bt->rchild, k, path, i + 1);  //在右子树中查找
	}
}
int main()
{
	BSTNode *bt;
	KeyType k = 6;
	int a[] = { 4,9,0,1,8,6,3,5,2,7 }, n = 10;
	printf("创建一颗BST树：");
	bt = CreateBST(a, n);
	printf("BST:");
	DispBST(bt);
	printf("\n");
	printf("bt%s\n", (JudgeBST(bt) ? "是一颗BST" : "不是一颗BST"));
	printf("\n");
	printf(" 查找%d关键字（顺序）：", k);
	SearchBST1(bt, k, path, -1);
}