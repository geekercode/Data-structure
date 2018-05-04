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
BTNode *CreateBT1(char *pre, char *in, int n) //pre����������У�in����������У�nΪ�������ڵ�ĸ���
{
	BTNode *s;
	char *p;
	int k;
	if (n <= 0)
		return NULL;
	s = (BTNode *)malloc(sizeof(BTNode));  //�����������ڵ�*s
	s->data = *pre;
	for (p = in; p < in + n; p++) //�������������ҵ���*pre��λ��k
		if (*p == *pre)           //preָ����ڵ�
			break;
	k = p - in;					  //ȷ�����ڵ���in�е�λ��
	s->lchild = CreateBT1(pre + 1, in, k); //�ݹ鹹��������
	s->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);//�ݹ鹹��������
	return s;
}
void main()
{
	BTNode *b;
	ElemType pre[] = "ABDEHJKLMNCFGI";
	ElemType in[] = "DBJHLKMNEAFCGI";
	
	b = CreateBT1(pre, in, 14);
	printf("�������У�%s\n", pre);
	printf("�������У�%s\n", in);
	printf("����һ�Ŷ�������\n");
	printf("���ű�ʾ����");
	DispBTNode(b);
	printf("\n");
}