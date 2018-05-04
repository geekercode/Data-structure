#include<stdio.h>
#include<malloc.h>
#define MaxSize 50
typedef struct
{
	int data[MaxSize];
	int length;
}Sqlist;
void move(Sqlist *&L)
{
	int i = 0, j = L->length - 1;
	int pivot = L->data[0];
	while (i != j)
	{
		while (j > i&&L->data[j] > pivot)
			j--;
		L->data[i] = L->data[j];
		while (i < j&&L->data[i] < pivot)
			i++;
		L->data[j] = L->data[i];
	}
	L->data[i] = pivot;
}
int main()
{   
	
	Sqlist *L = (Sqlist *)malloc(sizeof(Sqlist));
	int a[] = { 5,4,6,8,1,2,3,9 };
	L->length = sizeof(a) / sizeof(int);
	for (int i = 0; i < L->length; i++)
		L->data[i] = a[i];
	move(L);
	for (int i = 0; i < L->length; i++)
		printf("%3d", L->data[i]);


}