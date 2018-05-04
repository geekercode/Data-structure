#include<stdio.h>
#include<malloc.h>
#include"graph.h"

//------��Ȩͼ�㷨------
void MatToList1(MGraph g, ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{
	int i, j;
	ArcNode *p;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	for (i = 0; i<g.n; i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i<g.n; i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j = g.n - 1; j >= 0; j--)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)	//����һ����
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�*p
				p->adjvex = j;
				p->info = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;		//��*p���������
				G->adjlist[i].firstarc = p;
			}
	G->n = g.n; G->e = g.e;
}
void ListToMat1(ALGraph *G, MGraph &g)
//���ڽӱ�Gת�����ڽӾ���g
{
	int i, j;
	ArcNode *p;
	for (i = 0; i<G->n; i++)      	//g.edges[i][j]����ֵ0
		for (j = 0; j<G->n; j++)
			if (i == j)
				g.edges[i][j] = 0;
			else
				g.edges[i][j] = INF;
	for (i = 0; i<G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			g.edges[i][p->adjvex] = p->info;
			p = p->nextarc;
		}
	}
	g.n = G->n; g.e = G->e;
}
void DispMat1(MGraph g)
//����ڽӾ���g
{
	int i, j;
	for (i = 0; i<g.n; i++)
	{
		for (j = 0; j<g.n; j++)
			if (g.edges[i][j] == INF)
				printf("%3s", "��");
			else
				printf("%3d", g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj1(ALGraph *G)
//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i = 0; i<G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p != NULL)
		{
			printf("%3d(%d)", p->adjvex, p->info);
			p = p->nextarc;
		}
		printf("\n");
	}
}

int main()
{
	int i, j;
	MGraph g, g1;
	ALGraph *G;
	int A[MAXV][6] = {
		{ 0,5,INF,7,INF,INF },
		{ INF,0,4,INF,INF,INF },
		{ 8,INF,0,INF,INF,9 },
		{ INF,INF,5,0,INF,6 },
		{ INF,INF,INF,5,0,INF },
		{ 3,INF,INF,INF,1,0 } };
	g.n = 6;
	g.e = 10;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
	printf("����ͼG���ڽӾ���\n");
	DispMat1(g);
	G = (ALGraph *)malloc(sizeof(ALGraph));
	printf("�ڽӾ���ת��Ϊ�ڽӱ�\n");
	MatToList1(g, G);
	DispAdj1(G);
}