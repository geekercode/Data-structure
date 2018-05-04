#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

int cont = 0;
typedef struct
{
	int col[MaxSize];
	int top;

}StType;  //����˳��ջ����
int count = 0;
bool place(StType st, int i, int j)  //���ԣ�i��j���Ƿ���1-i-1�г�ͻ
{
	int k = 1;
	if (i == 1)
		return true;
	//��ǰi-1�У����п���

	while (k <= i - 1)
	{
		if ((st.col[k] == j) || (abs(k - i) == abs(j - st.col[k])))
			return false;
		k++;
	}
	return true;
}
void queen(int n)
{
	int i, j, k;
	bool find;
	StType st;
	st.top = 0;
	st.top++;
	st.col[st.top] = 1;
	while (st.top > 0)
	{
		i = st.top;
		if (st.top == n)
		{
			printf(" ��%d���⣺",++count);
			for (k = 1; k <= st.top; k++)
				printf("(%d,%d)", k, st.col[k]);
			printf("\n");
		}
		find = false;
		for(j=1;j<=n;j++)
			if (place(st, i + 1, j))
			{
				st.top++;
				st.col[st.top] = j;
				find = true;
				break;
			}
		if (find == false)
		{
			while (st.top > 0)
			{
				if (st.col[st.top] == n)
					st.top--;
				for(j=st.col[st.top]+1;j<=n;j++)
					if (place(st, st.top, j))
					{
						st.col[st.top] = j;
						break;
					}
				if (j > n)
					st.top--;
				else
					break;
			}
		}
	}
}
void main()
{
	int n=4;
	/*printf("�ʺ����⣨n<20)n=");
	scanf("%d", &n);*/
	if (n > 20)
		printf("the value of n is too large");
	else
	{
		printf("%d �ʺ�����������£�\n", n);
		queen(n);
		printf("\n");
	}
}