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
			R[j + 1] = R[j];  //���ؼ��ִ���R[i].key�ļ�¼����
			j--;
		}
		R[j + 1] = temp;  //��j+1������R[i]
		printf("i=%d", i);
		printf("����%d�����Ϊ��", temp);
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
	printf("��ʼ�ؼ���Ϊ��");
	for (k = 0; k < n; k++)
		printf(" %3d", R[k].key);
	printf("\n");
	InsertSort(R, n);
	printf("�����Ϊ��");
	for (k = 0; k < n; k++)
		printf(" %3d", R[k].key);
	printf("\n");
}