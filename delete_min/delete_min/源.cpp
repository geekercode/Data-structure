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
