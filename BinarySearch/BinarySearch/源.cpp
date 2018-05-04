#include<stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];
int BinSearch(SeqList R, int n, KeyType k)
{
	int  low = 0, high = n - 1, mid, count = 0;
	while (low <= high)
	{
		mid = (high + low) / 2;
		printf("  第%d次比较：在[ %d, %d]中比较元素R[%d]:%d\n", ++count, low, high, mid, R[mid].key);
		if (R[mid].key == k)
			return mid;
		if (R[mid].key > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int main()
{
	SeqList R;
	KeyType k = 9;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i, n = 10;
	for (i = 0; i < n; i++)  // 建立顺序表
		R[i].key = a[i];
	printf("关键字序列：");
	for (i = 0; i < n; i++)
		printf(" %d", R[i].key);
	printf("\n");
	printf("查找%d的比较过程如下：\n", k);
	if ((i = BinSearch(R, n, k) != -1))
		printf("元素%d的位置是%d\n", k, i);
	else
		printf("元素%d不在表中\n", k);
}