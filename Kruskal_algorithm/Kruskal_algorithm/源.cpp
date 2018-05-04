#include"graph.h"
#include<stdio.h>
#define MAXE 100
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
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
void SortEdge(MGraph g, Edge E[])  //邻接矩阵产生权值递增的边集
{
	int i, j, k = 0;
	Edge temp;
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			if (g.edges[i][j] < INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
	for (i = 1; i < k; i++)
	{
		temp = E[i];
		j = i - 1;
		while (j >= 0 && temp.w < E[j].w)
		{
			E[j + 1] = E[j];
			j--;
		}
		E[j + 1] = temp;
	}

}
void KrusKal(Edge E[], int n, int e)
{
	int i, j, m1, m2, sn1, sn2, k;
	int vset[MAXE];
	for (i = 0; i < n; i++)
		vset[i] = i;
	k = 1;
	j = 0;
	while (k < n)
	{
		m1 = E[j].u;
		m2 = E[j].v;
		sn1 = vset[m1];
		sn2 = vset[m2];
		if (sn1 != sn2)
		{
			printf("  (%d,%d):%d\n", m1, m2, E[j].w);
			k++;
			for (i = 0; i < n; i++)
				if (vset[i] == sn2)
					vset[i] = sn1;

		}
		j++;
	}
 }
void main()
{
	int i, j, u = 3;
	MGraph g;
	Edge E[MAXE];
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
	SortEdge(g, E);
	printf("图G的邻接矩阵是：\n");
	DispMat1(g);
	printf("克鲁斯卡尔算法求解结果：\n");
	KrusKal(E, g.n, g.e);
	printf("\n");
}