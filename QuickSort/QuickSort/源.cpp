#include<stdio.h>

void QuickSort(int R[], int low ,int high)
{
	int i=low, j=high, temp;
	if (low < high)
	{
		temp = R[low];
		while (i != j)
		{
			while (i < j&&R[j] >= temp)
				j--; //���������ҵ���һ��С��temp����
			R[i] = R[j];  //R[j]�ŵ�R[i]��λ��
		    while (i < j&&R[i] <= temp)
				i++;
			R[j] = R[i];  //R[j]�ŵ�R[i]��λ��
		}
		R[i] = temp;
		QuickSort(R, low, i - 1);
		QuickSort(R, i + 1, high);
	}
	
	
}

int main()
{
	int R[] = { 6,8,7,9,0,1,3,2,4,5 };
	int n = (int)sizeof(R) / sizeof(*R);
	printf("ԭ�� ");
	for (int i = 0; i < n; i++)
	{
		printf("%3d", R[i]);
	}
	QuickSort(R, 0, n - 1);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%3d", R[i]);
	}
              
}