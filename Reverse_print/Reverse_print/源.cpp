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
void R_print(LinkList *L) {
	if (L!= NULL)
	{
		R_print(L->next);
		printf("%c\n", L->data);
	}
	
}
int main() {
	LinkList *L;
	//L = (LinkList *)malloc(sizeof(LinkList));	//创建头结点
	//L->next = NULL;
	ElemType a[] = { 'c','a','e','h' };
	CreateListR(L, a, 4);
	R_print(L);
	
}