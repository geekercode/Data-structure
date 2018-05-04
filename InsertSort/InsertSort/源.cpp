#include<stdio.h>
#define MAXE 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
	KeyType key;
	InfoType data;
}RecType;
void InsertSort(RecType R[], int n)
{
	int i, j, k;
	RecType temp;
	for (i = 1; i < n; i++)
	{
		temp = R[i]; 
		j = i - 1;
		while (j >= 0 && temp.key < R[j].key)
		{
			R[j + 1] = R[j];  //将关键字大于R[i].key的记录后移
			j--;
		}
		R[j + 1] = temp;  //在j+1处插入R[i]
		printf("i=%d", i);
		printf("插入%d，结果为：", temp);
		for (k = 0; k < n; k++)
			printf("%3d", R[k].key);
		printf("\n");
	}
}

int main()
{
	int i, k, n = 10;
	KeyType a[] = { 9,8,7,6,5,4,3,2,1,0 };
	RecType R[MAXE];
	for (i = 0; i < n; i++)
		R[i].key = a[i];
	printf("初始关键字为：");
	for (k = 0; k < n; k++)
		printf(" %3d", R[k].key);
	printf("\n");
	InsertSort(R, n);
	printf("最后结果为：");
	for (k = 0; k < n; k++)
		printf(" %3d", R[k].key);
	printf("\n");
}