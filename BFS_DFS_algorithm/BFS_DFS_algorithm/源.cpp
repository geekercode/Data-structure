#include<stdio.h>
#include<malloc.h>
#include"graph.h"
int visited[MAXV];
void DFS(ALGraph *G, int v)   //�ݹ�������ȱ���
{
	ArcNode *p;  
	visited[v] = 1;
	printf("%3d", v); //��������ʽڵ�ı��
	p = G->adjlist[v].firstarc; //pָ�򶥵�V�ĵ�һ���ߵı�ͷ�ڵ�
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}
void BFS(ALGraph *G, int v)
{
	ArcNode *p;
	int queue[MAXV], front = 0, rear = 0; //����ѭ�����鲢��ʼ��
	int visited[MAXV];
	int w, i;
	for (i = 0; i < G->n; i++)
		visited[i] = 0;
	printf("%3d", v);
	visited[v] = 1;
	rear = (rear + 1) % MAXV;
	queue[rear] = v;
	while (front != rear)
	{
		front = (front + 1) % MAXV;
		w = queue[front];          //���Ӳ�����w
		p = G->adjlist[w].firstarc;//���붥��w���ڵĵ�һ������
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%3d", p->adjvex);
				visited[p->adjvex] = 1;
				rear = (rear + 1) % MAXV;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
	printf("\n");

}
void MatToList1(MGraph g, ALGraph *&G)
//���ڽӾ���ת��Ϊ�ڽӱ�
{
	int i, j;
	ArcNode *p;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	for (i = 0; i < g.n; i++)   //���ڽӱ�����ͷ����ָ���ó�ֵ
		G->adjlist[i].firstarc = NULL;  //adjlist[v]��ʾ��v������
	for(i=0;i<g.n;i++)
		for(j=g.n-1;j>=0;j--)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->info = g.edges[j][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;

			}
	G->n = g.n;
	G->e = g.e;
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
int Connect(ALGraph *G)
{
	int i, flag = 1;
	for (i = 0; i < G->n; i++)
		visited[i] = 0;
	DFS(G, 0);
	for(i=0;i<G->n;i++)
		if (visited[i] == 0)
		{
			flag = 0;
			break;
		}
	return flag;
}
void main()
{
	int i, j;
	MGraph g;  //ͼ���ڽӾ�������
	ALGraph *G;//ͼ���ڽӱ�����
	int A[MAXV][6] = {
		{ 0,5,INF,7,INF,INF },
		{ INF,0,4,INF,INF,INF },
		{ 8,INF,0,INF,INF,9 },
		{ INF,INF,5,0,INF,6 },
		{ INF,INF,INF,5,0,INF },
		{ 3,INF,INF,INF,1,0 } };
	g.n = 6;
	g.e = 10;
	for (i = 0; i < g.n; i++)   //g.n��������
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
	G = (ALGraph *)malloc(sizeof(ALGraph));
	MatToList1(g, G);
	printf("ͼ���ڽӱ�\n");
	DispAdj1(G);
	printf("��0��ʼ��DFS�ݹ��㷨��\n");
	DFS(G, 0);
	printf("\n");
	printf("�Ӷ���0��ʼ��BFS�ǵݹ��㷨��\n");
	BFS(G, 0);
	printf("\n");
	printf(" bool�����%d", Connect(G));
	printf("\n");
}