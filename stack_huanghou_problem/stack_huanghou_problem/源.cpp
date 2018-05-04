#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

int cont = 0;
typedef struct
{
	int col[MaxSize];
	int top;

}StType;  //定义顺序栈类型
int count = 0;
bool place(StType st, int i, int j)  //测试（i，j）是否与1-i-1有冲突
{
	int k = 1;
	if (i == 1)
		return true;
	//对前i-1行，逐行考察

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
			printf(" 第%d个解：",++count);
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
	/*printf("皇后问题（n<20)n=");
	scanf("%d", &n);*/
	if (n > 20)
		printf("the value of n is too large");
	else
	{
		printf("%d 皇后问题求解如下：\n", n);
		queen(n);
		printf("\n");
	}
}