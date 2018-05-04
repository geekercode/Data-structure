#include<stdio.h>
#include"graph.h"
void DispMat1(MGraph g)
//输出邻接矩阵g
{
	int i, j;
	for (i = 0; i<g.n; i++)
	{
		for (j = 0; j<g.n; j++)
			if (g.edges[i][j] == INF)
				printf("%3s", "∞");
			else
				printf("%3d", g.edges[i][j]);
		printf("\n");
	}
}
void Prim(MGraph g, int v)
{
	int lowcost[MAXV], min, n = g.n;
	int closest[MAXV], i, j, k;
	for (i = 0; i < n; i++)
	{
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < n; i++)
	{
		min = INF;
		for (j = 0; j < n; j++)
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		printf("边(%d,%d)权为：%d\n", closest[k], k, min);
		lowcost[k] = 0;
		for(j=0;j<n;j++)
			if (g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}

int main()
{
	int i, j, u = 3;
	MGraph g;
	int A[MAXV][MAXV] = { { 0,5,8,7,INF,3 },
	{ 5,0,4,INF,INF,INF },
	{ 8,4,0,5,INF,9 },
	{ 7,INF,5,0,5,INF },
	{ INF,INF,INF,5,0,1 },
	{ 3,INF,9,INF,1,0 } };
	g.n = 6;
	g.e = 10;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
	printf("图G的邻接矩阵为:\n");
	DispMat1(g);
	printf("prim算法的求解结果：\n");
	Prim(g, 0);
	printf("\n");
}