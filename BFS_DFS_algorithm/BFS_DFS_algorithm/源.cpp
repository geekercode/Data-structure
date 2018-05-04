#include<stdio.h>
#include<malloc.h>
#include"graph.h"
int visited[MAXV];
void DFS(ALGraph *G, int v)   //递归深度优先遍历
{
	ArcNode *p;  
	visited[v] = 1;
	printf("%3d", v); //输出被访问节点的编号
	p = G->adjlist[v].firstarc; //p指向顶点V的第一条边的边头节点
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
	int queue[MAXV], front = 0, rear = 0; //定义循环数组并初始化
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
		w = queue[front];          //出队并赋给w
		p = G->adjlist[w].firstarc;//找与顶点w相邻的第一个顶点
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
//将邻接矩阵转换为邻接表
{
	int i, j;
	ArcNode *p;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	for (i = 0; i < g.n; i++)   //给邻接表所有头结点的指针置初值
		G->adjlist[i].firstarc = NULL;  //adjlist[v]表示第v个顶点
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
//输出邻接表G
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
	MGraph g;  //图的邻接矩阵类型
	ALGraph *G;//图的邻接表类型
	int A[MAXV][6] = {
		{ 0,5,INF,7,INF,INF },
		{ INF,0,4,INF,INF,INF },
		{ 8,INF,0,INF,INF,9 },
		{ INF,INF,5,0,INF,6 },
		{ INF,INF,INF,5,0,INF },
		{ 3,INF,INF,INF,1,0 } };
	g.n = 6;
	g.e = 10;
	for (i = 0; i < g.n; i++)   //g.n代表顶点数
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
	G = (ALGraph *)malloc(sizeof(ALGraph));
	MatToList1(g, G);
	printf("图的邻接表：\n");
	DispAdj1(G);
	printf("从0开始的DFS递归算法：\n");
	DFS(G, 0);
	printf("\n");
	printf("从顶点0开始的BFS非递归算法：\n");
	BFS(G, 0);
	printf("\n");
	printf(" bool结果是%d", Connect(G));
	printf("\n");
}