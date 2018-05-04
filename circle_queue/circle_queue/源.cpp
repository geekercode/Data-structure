#include<stdio.h>
#include<malloc.h>
#define MaxSize 5
typedef char elemtype;
//采用队列的顺序存储结构，使用一个数组和两个整数型变量来实现，利用数组顺序存储队列中的所有元素
typedef struct             
{
	elemtype data[MaxSize];
	int front, rear;
}SqQueue;
void InitQueue(SqQueue *&q) //初始化队列
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;

}
bool Empty(SqQueue *q)
{
	return(q->front == q->rear);
}
bool EnQueue(SqQueue *&q, elemtype e) 
{
	if ((q->rear + 1) % MaxSize == q->front)
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool DeQueue(SqQueue *&q, elemtype &e)
{
	if (q->front == q->rear)
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}
void main()
{
	elemtype e;
	SqQueue *q;
	InitQueue(q);
	if (!EnQueue(q, 'a')) printf("\t提示:队满,不能进队\n");
	if (!EnQueue(q, 'b')) printf("\t提示:队满,不能进队\n");
	if (!EnQueue(q, 'c')) printf("\t提示:队满,不能进队\n");
	printf("  (3)队列为%s\n", (Empty(q) ? "空" : "非空"));
	if (DeQueue(q, e) == 0)
		printf("队空,不能出队\n");
	else
		printf("  (4)出队一个元素%c\n", e);
	printf("  (5)依次进队列元素d,e,f\n");
	if (!EnQueue(q, 'd')) printf("\t提示:队满,不能进队\n");
	if (!EnQueue(q, 'e')) printf("\t提示:队满,不能进队\n");
	if (!EnQueue(q, 'f')) printf("\t提示:队满,不能进队\n");
	printf("  (6)出队列序列:");
	while (!Empty(q))
	{
		DeQueue(q, e);
		printf("%c ", e);
	}
	printf("\n");
	
}