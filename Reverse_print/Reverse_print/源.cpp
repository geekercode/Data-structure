#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode	//���嵥����������
{
	ElemType data;
	struct LNode *next;
} LinkList;
void CreateListR(LinkList *&L, ElemType a[], int n) //β�巨����
{
	LinkList *s, *r; int i;
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
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}
void R_print(LinkList *L) {
	if (L!= NULL)
	{
		R_print(L->next);
		printf("%c\n", L->data);
	}
	
}
int main() {
	LinkList *L;
	//L = (LinkList *)malloc(sizeof(LinkList));	//����ͷ���
	//L->next = NULL;
	ElemType a[] = { 'c','a','e','h' };
	CreateListR(L, a, 4);
	R_print(L);
	
}