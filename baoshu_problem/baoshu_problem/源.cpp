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
	printf("��������˳��");
	while (q.front != q.rear) //���в���ʱѭ��
	{
		q.front = (q.front + 1) % MaxSize;
		e = q.data[q.front];
		printf("%d ", e);  //����һ��Ԫ��
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
	printf("��ʼ���У�");
	for (i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");
	number(n);
}