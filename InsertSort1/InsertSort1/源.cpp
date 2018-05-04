#include<stdio.h>

void InsertSort(int R[], int n)
{
	int i, j;
	int temp;
	for (i = 0; i < n; i++) 
	{
		temp = R[i];
		j = i - 1;
		while (j >= 0 && temp < R[j])
		{
			R[j + 1] = R[j];
			--j;
		}
		R[j + 1] = temp;
	}
}


int main()
{
	int a[] = { 5,6,3,4,1,8,9,7 };
	int R[8];
	for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
		R[i] = a[i];
	int n = sizeof(a) / sizeof(*a);
	InsertSort(R, n);
	for (int i = 0; i < n; i++)
		printf("%3d", R[i]);
	printf("\n");
}