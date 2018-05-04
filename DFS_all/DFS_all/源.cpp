#include<stdio.h>
#include<malloc.h>
#include"graph.h"
int visited[MAXV];
void MatToList(MGraph g, ALGraph *&G)
//将邻接矩阵g转换成邻接表G
{
	int i, j;
	ArcNode *p;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	for (i = 0; i<g.n; i++)					//给邻接表中所有头节点的指针域置初值
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i<g.n; i++)					//检查邻接矩阵中每个元素
		for (j = g.n - 1; j >= 0; j--)
			if (g.edges[i][j] != 0)		//邻接矩阵的当前元素不为0
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));	//创建一个节点*p
				p->adjvex = j;
				p->nextarc = G->adjlist[i].firstarc;		//将*p链到链表后
				G->adjlist[i].firstarc = p;
			}
	G->n = g.n; G->e = g.e;
}
void DispAdj(ALGraph *G)	//输出邻接表G
{
	int i;
	ArcNode *p;
	for (i = 0; i<G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p != NULL)
		{
			printf("%3d", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}
void DFSALL(ALGraph *G, int v, int path[], int d)
{
	ArcNode *p;
	visited[v] = 1;
	path[d] = v;
	d++;
	if (d == G->n)  //已经访问完所有的顶点，输出序列
	{
		for (int k = 0; k < d; k++)
			printf("%2d", path[k]);
		printf("\n");
	}
	p = G->adjlist[v].firstarc;
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			DFSALL(G, p->adjvex, path, d);
		p = p->nextarc;
	}
	visited[v] = 0;
}
void main()
{
	int path[MAXV], i, j, v = 1;
	MGraph g;
	ALGraph *G;
	g.n = 5;
	g.e = 8;
	int A[MAXV][MAXV] = {
		{ 0,1,0,1,1 },
		{ 1,0,1,1,0 },
		{ 0,1,0,1,1 },
		{ 1,1,1,0,1 },
		{ 1,0,1,1,0 } };
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
	MatToList(g, G);
	for (i = 0; i < g.n; i++)
		visited[i] = 0;
	printf("图的邻接表：\n");
	DispAdj(G);
	printf("从顶点%d出发的所有深度优先序列:\n", v);
	DFSALL(G, v, path, 0);
	printf("\n");

}