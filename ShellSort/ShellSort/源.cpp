#include<stdio.h>
#define MAXE 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
	KeyType key;
	InfoType data;
}RecType;
void ShellSort(RecType R[], int n)
{
	int i, j, d, k;
	RecType temp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{
			j = i - d;
			while (j >= 0 && R[j].key > R[j + d].key)
			{
				temp = R[j];
				R[j] = R[j + d];
				R[j + d] = temp;
				j = j - d;
			}
		}
		printf("d=%d: ", d);
		for (k = 0; k < n; k++)
			printf(" %3d", R[k].key);
		printf("\n");
		d = d / 2;
	}
}
void main()
{
	int i, k, n = 10;
	KeyType a[] = { 9,8,7,6,5,4,3,2,1,0 };
	RecType R[MAXE];
	for (i = 0; i < n; i++)
		R[i].key = a[i];
	printf("初始关键字：");
	for (k = 0; k < n; k++)
		printf("%3d", R[k].key);
	printf("\n");
	ShellSort(R, n);
	printf("最后结果为：");
	for (k = 0; k < n; k++)
		printf("%3d", R[k].key);
	printf("\n\n");
}