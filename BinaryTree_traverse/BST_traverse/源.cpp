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
void PreOrder(BTNode *b)  //��������ĵݹ��㷨
{
	if (b != NULL)
	{
		printf("%c ", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
void InOrder(BTNode *b) //��������ݹ��㷨
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
			while (p != NULL)  //ɨ��*p���е����㲢��ջ
			{
				top++;
				St[top] = p;
				p = p->lchild;
			}

			if (top > -1)
			{
				p = St[top]; //��ջp���
				top--;
				printf("%c ", p->data); //����֮
				p = p->rchild; //ת����*p���Һ��ӽڵ�
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
	front = rear = 0;   //����һ������
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
	printf("�������Ļ�����������:\n");
	printf("  (1)���������:"); DispBTNode(b); printf("\n");
	printf("��α����㷨��");
	TraverseLevel(b);
	printf("��������㷨��");
	PreOrder(b);
	printf("\n");
	printf("��������㷨��");
	InOrder(b);
	printf("\n");
	printf("��������ǵݹ��㷨��");
	InOrder1(b);
	printf("\n");
	
}