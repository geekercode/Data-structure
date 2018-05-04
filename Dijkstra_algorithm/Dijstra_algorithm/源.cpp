#include<stdio.h>
#include"graph.h"
#define MAXV 100

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
void ppath(int path[], int i, int v)  //前向递归查找路径上的顶点
{
	int k;
	k = path[i];
	if (k == v)
		return;
	ppath(path, k, v);
	printf("%d,", k);
}
void DisPath(int dist[], int path[], int s[], int n, int v)
{
	int i;
	printf("   path:");
	for (i = 0; i < n; i++)
		printf("%3d", path[i]);
	printf("\n");
	for (i = 0; i < n; i++)
		if (s[i] == 1)
		{
			if (i != v)
			{
				printf(" 从%d到%d的最短路径长度为：%d\t路径为：", v, i, dist[i]);
				printf("%d,", v);
				ppath(path, i, v);
				printf("%d\n", i);
			}
		}
		else
			printf(" 从%d到%d不存在路径\n", v, i);
}
void Dijkstra(MGraph g, int v)
{
	int dist[MAXV], path[MAXV];
	int s[MAXV];
	int mindis, i, j, u, n = g.n;
	for (i = 0; i < n; i++)
	{
		dist[i] = g.edges[v][i]; //距离初始化
		s[i] = 0;          
		if (g.edges[v][i] < INF) //路径初始化
			path[i] = v;
		else
			path[i] = -1;

	}
	s[v] = 1;               //源点编号v放入s中
	path[v] = 0;
	for (i = 0; i < n; i++) //循环直到所有顶点的最短路径都求出
	{
		mindis = INF;
		u = -1;
		for(j=0;j<n;j++)  //选取不在s中并且具有最小距离的顶点u
			if (s[j] == 0 && dist[j] < mindis)
			{
				u = j;
				mindis = dist[j];
			}
		s[u] = 1;         //顶点u加入s中
		for(j=0;j<n;j++)  //修改不在s中的顶点的距离
			if(s[j]==0)
				if (g.edges[u][j] < INF&&dist[u] + g.edges[u][j] < dist[j])
				{
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}

	}
	printf("输出最短路径：\n");
	DisPath(dist, path, s, n, v); //输出最短路径

}
void main()
{
	int i, j, u = 0;
	MGraph g;
	int A[MAXV][6] = {
		{ 0,5,INF,7,INF,INF },
		{ INF,0,4,INF,INF,INF },
		{ 8,INF,0,INF,INF,9 },
		{ INF,INF,5,0,INF,6 },
		{ INF,INF,INF,5,0,INF },
		{ 3,INF,INF,INF,1,0 } };
	g.n = 6; g.e = 10;
	for (i = 0; i<g.n; i++)		//建立图8.1的邻接矩阵
		for (j = 0; j<g.n; j++)
			g.edges[i][j] = A[i][j];
	printf("有向图的邻接矩阵为：\n");
	DispMat1(g);
	Dijkstra(g, u);
	printf("\n");
}