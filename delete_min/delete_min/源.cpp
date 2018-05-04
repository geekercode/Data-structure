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
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
LinkList DelMin(LinkList *head)
{
	LinkList *pre = head, *p = head->next;
	LinkList *premin = pre, *min = p;
	while (p) {
		if (min->data > p->data) {
			premin = pre;
			min = p;
		}
		pre = p;
		p = p->next;
	}
	printf("Deleted Node: %4d\n", min->data);
	premin->next = min->next;
	free(min);
	return head;
}
int main(){
	LinkList *head;
	ElemType a[] = {3,5,6,8,1 };
	CreateListR(head, a, 5);
	DispList(head);

}
