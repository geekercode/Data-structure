#include "list.h"
#include <stdio.h>

//删除线性表中，元素值在x到y之间的元素
void delx2y(SqList *&L, ElemType x, ElemType y)
{
	int k = 0, i; //k记录非x的元素个数
	ElemType t;
	if (x>y)
	{
		t = x;
		x = y;
		y = t;
	}
	for (i = 0; i<L->length; i++)
		if (L->data[i]<x || L->data[i]>y)  //复制不在[x, y]之间的元素
		{
			L->data[k] = L->data[i];
			k++;
		}
	L->length = k;
}

//用main写测试代码
int main()
{
	SqList *sq;
	ElemType a[10] = { 5,8,7,0,2,4,9,6,7,3 };
	CreateList(sq, a, 10);
	printf("删除前 ");
	DispList(sq);

	delx2y(sq, 4, 7);

	printf("删除后 ");
	DispList(sq);
	return 0;
}