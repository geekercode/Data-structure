#include "list.h"
#include <stdio.h>

//移动结束后，奇数居左，偶数居右
void move(SqList *&L)
{
	int i = 0, j = L->length - 1;
	ElemType tmp;
	while (i<j)
	{
		while (i<j && L->data[j] % 2 == 0)  //从右往左，找到第一个奇数(偶数就忽略不管)
			j--;
		while (i<j && L->data[i] % 2 == 1)  //从左往右，找到第一个偶数(奇数就忽略不管)
			i++;
		if (i<j)   //如果未到达“分界线”，将右边的奇数和左边的偶数交换
		{
			tmp = L->data[i];
			L->data[i] = L->data[j];
			L->data[j] = tmp;
		}
	}   //待循环上去后，继续查找，并在必要时交换
}


//用main写测试代码
int main()
{
	SqList *sq;
	ElemType a[10] = { 5,8,7,0,2,4,9,6,7,3 };
	CreateList(sq, a, 10);
	printf("操作前 ");
	DispList(sq);

	move(sq);

	printf("操作后 ");
	DispList(sq);
	return 0;
}