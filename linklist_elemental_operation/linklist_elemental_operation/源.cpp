#include<stdio.h>
#include<malloc.h>
typedef int elemtype;
typedef struct LNode {
	elemtype data;
	struct LNode *next;

}LinkList;
void CreateListR(LinkList *&L, elemtype a[], int n)//尾插法建立单链表
{
	LinkList *s, *r;
	int i;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
	r = L;
	for (i = 0; i < n; i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		r->next = s;
		r = s;

	}
	r->next = NULL;
}
void DispList(LinkList*L)
{
	LinkList *p = L->next;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n");
}
int main() {
	LinkList *head;
	elemtype a[] = { 1,2,4,6,5,8 };
	CreateListR(head, a, 6);
	DispList(head);
}