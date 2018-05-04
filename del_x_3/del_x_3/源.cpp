#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode	//���嵥����������
{
	ElemType data;
	struct LNode *next;
}LinkList;
void CreateListR(LinkList *&L, ElemType a[], int n) //β�巨����
{
	LinkList *s, *r; 
	int i;
	L = (LinkList *)malloc(sizeof(LinkList));	//����ͷ���
	L->next = NULL;
	r = L;						//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (i = 0; i<n; i++)
	{
		s = (LinkList *)malloc(sizeof(LinkList));//�����½��
		s->data = a[i];
		r->next = s;				//��*s����*r֮��
		r = s;
	}
	r->next = NULL;				//�ն˽��next����ΪNULL
}
void DispList(LinkList *L)		//������Ա�
{
	LinkList *p = L->next;
	while (p != L)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void Del_X_3(LinkList *&L, int x)
{
	LinkList *p;//pָ���ɾ�����
	if (L==NULL)
		return;
	if (L->data == x)
	{
		p = L;
		L = L->next;
		free(p);
		Del_X_3(L, x);//�ݹ����
	}
	else
		Del_X_3(L->next, x);//�ݹ����
}

int main() {
	LinkList *L;
	ElemType a[] = { 1,2,3,4,5,6 };
	CreateListR(L, a, 6);
	Del_X_3(L, 4);
	DispList(L);

}