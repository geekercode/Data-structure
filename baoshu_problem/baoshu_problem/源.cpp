#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;
void number(int n)
{
	int i;
	ElemType e;
	SqQueue q;
	q.front = q.rear = 0;
	for (i = 1; i <= n; i++)
	{
		q.rear = (q.rear + 1) % MaxSize;
		q.data[q.rear] = i;
	}
	printf("报数出列顺序：");
	while (q.front != q.rear) //队列不空时循环
	{
		q.front = (q.front + 1) % MaxSize;
		e = q.data[q.front];
		printf("%d ", e);  //出队一个元素
		if (q.front != q.rear)
		{
			q.front = (q.front + 1) % MaxSize;
			e = q.data[q.front];
			q.rear = (q.rear + 1) % MaxSize;
			q.data[q.rear] = e;
		}
	}
	printf("\n");
}
void main()
{
	int i, n = 8;
	printf("初始序列：");
	for (i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");
	number(n);
}