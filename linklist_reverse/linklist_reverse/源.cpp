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
void reverse(LinkList *L) {
	LinkList *p = L->next, *q;
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
	
}
int main() {
	LinkList *L;
	ElemType a[] = { 'c','a','e','h','k','p' };
	CreateListR(L, a, 6);
	reverse(L);
	DispList(L);

}