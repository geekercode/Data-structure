#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode	//定义单链表结点类型
{
	ElemType data;
	struct LNode *next;
}LinkList;
void CreateListR(LinkList *&L, ElemType a[], int n) //尾插法建表
{
	LinkList *s, *r; 
	int i;
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
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void Del_X_3(LinkList *&L, int x)
{
	LinkList *p;//p指向待删除结点
	if (L==NULL)
		return;
	if (L->data == x)
	{
		p = L;
		L = L->next;
		free(p);
		Del_X_3(L, x);//递归调用
	}
	else
		Del_X_3(L->next, x);//递归调用
}

int main() {
	LinkList *L;
	ElemType a[] = { 1,2,3,4,5,6 };
	CreateListR(L, a, 6);
	Del_X_3(L, 4);
	DispList(L);

}