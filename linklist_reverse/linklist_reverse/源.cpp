#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode	//定义单链表结点类型
{
	ElemType data;
	struct LNode *next;
} LinkList;
void CreateListR(LinkList *&L, ElemType a[], int n) //尾插法建表
{
	LinkList *s, *r; int i;
	L = (LinkList *)malloc(sizeof(LinkList));	//创建头结点
	L->next = NULL;
	r = L;						//r始终指向终端结点,开始时指向头结点
	for (i = 0; i<n; i++)
	{
		s = (LinkList *)malloc(sizeof(LinkList));//创建新结点
		s->data = a[i];
		r->next = s;				//将*s插入*r之后
		r = s;
	}
	r->next = NULL;				//终端结点next域置为NULL
}
void DispList(LinkList *L)		//输出线性表
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