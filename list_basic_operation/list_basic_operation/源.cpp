#include "list.h"
#include <stdio.h>

//ɾ�����Ա��У�Ԫ��ֵ��x��y֮���Ԫ��
void delx2y(SqList *&L, ElemType x, ElemType y)
{
	int k = 0, i; //k��¼��x��Ԫ�ظ���
	ElemType t;
	if (x>y)
	{
		t = x;
		x = y;
		y = t;
	}
	for (i = 0; i<L->length; i++)
		if (L->data[i]<x || L->data[i]>y)  //���Ʋ���[x, y]֮���Ԫ��
		{
			L->data[k] = L->data[i];
			k++;
		}
	L->length = k;
}

//��mainд���Դ���
int main()
{
	SqList *sq;
	ElemType a[10] = { 5,8,7,0,2,4,9,6,7,3 };
	CreateList(sq, a, 10);
	printf("ɾ��ǰ ");
	DispList(sq);

	delx2y(sq, 4, 7);

	printf("ɾ���� ");
	DispList(sq);
	return 0;
}