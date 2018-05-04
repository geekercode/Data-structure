#include<stdio.h>
#include<malloc.h>
#include"graph.h"
int visited[MAXV];
void MatToList(MGraph g, ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{
	int i, j;
	ArcNode *p;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	for (i = 0; i<g.n; i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i<g.n; i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j = g.n - 1; j >= 0; j--)
			if (g.edges[i][j] != 0)		//�ڽӾ���ĵ�ǰԪ�ز�Ϊ0
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�*p
				p->adjvex = j;
				p->nextarc = G->adjlist[i].firstarc;		//��*p���������
				G->adjlist[i].firstarc = p;
			}
	G->n = g.n; G->e = g.e;
}
void DispAdj(ALGraph *G)	//����ڽӱ�G
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
	if (d == G->n)  //�Ѿ����������еĶ��㣬�������
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
	printf("ͼ���ڽӱ�\n");
	DispAdj(G);
	printf("�Ӷ���%d���������������������:\n", v);
	DFSALL(G, v, path, 0);
	printf("\n");

}