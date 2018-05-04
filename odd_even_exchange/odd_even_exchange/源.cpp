#include "list.h"
#include <stdio.h>

//�ƶ���������������ż������
void move(SqList *&L)
{
	int i = 0, j = L->length - 1;
	ElemType tmp;
	while (i<j)
	{
		while (i<j && L->data[j] % 2 == 0)  //���������ҵ���һ������(ż���ͺ��Բ���)
			j--;
		while (i<j && L->data[i] % 2 == 1)  //�������ң��ҵ���һ��ż��(�����ͺ��Բ���)
			i++;
		if (i<j)   //���δ����ֽ��ߡ������ұߵ���������ߵ�ż������
		{
			tmp = L->data[i];
			L->data[i] = L->data[j];
			L->data[j] = tmp;
		}
	}   //��ѭ����ȥ�󣬼������ң����ڱ�Ҫʱ����
}


//��mainд���Դ���
int main()
{
	SqList *sq;
	ElemType a[10] = { 5,8,7,0,2,4,9,6,7,3 };
	CreateList(sq, a, 10);
	printf("����ǰ ");
	DispList(sq);

	move(sq);

	printf("������ ");
	DispList(sq);
	return 0;
}