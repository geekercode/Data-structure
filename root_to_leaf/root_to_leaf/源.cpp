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
void CreateBTNode(BTNode *&b, char *str)		//��str������������
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0')	//strδɨ����ʱѭ��
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//Ϊ��ڵ�
		case ')':top--; break;
		case ',':k = 2; break;                      	//Ϊ�ҽڵ�
		default:p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    //pָ��������ĸ��ڵ�
				b = p;
			else  							//�ѽ������������ڵ�
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
void DispBTNode(BTNode *b)	//�����ű�ʾ�����������
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
			printf("   %c�����ڵ���·��: %c ", b->data, b->data); //�����Ҷ�ӽ��
			for (i = pathlen - 1; i >= 0; i--)
				printf("%c ", path[i]);     //ջ�еĽڵ��ջ
			printf("\n");

		}
		else
		{
			path[pathlen] = b->data;     //�Ӹ��ڵ㵽Ҷ�ӽ������ջ
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
	printf("������b:\n");
	DispBTNode(b);
	printf("\n");
	printf("Ҷ�ӽ�㣺");
	DispLeaf(b);
	printf("\n");
	printf("allpath1:\n");
	AllPath1(b, path, 0);
}