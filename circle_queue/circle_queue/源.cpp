#include<stdio.h>
#include<malloc.h>
#define MaxSize 5
typedef char elemtype;
//���ö��е�˳��洢�ṹ��ʹ��һ����������������ͱ�����ʵ�֣���������˳��洢�����е�����Ԫ��
typedef struct             
{
	elemtype data[MaxSize];
	int front, rear;
}SqQueue;
void InitQueue(SqQueue *&q) //��ʼ������
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
	if (!EnQueue(q, 'a')) printf("\t��ʾ:����,���ܽ���\n");
	if (!EnQueue(q, 'b')) printf("\t��ʾ:����,���ܽ���\n");
	if (!EnQueue(q, 'c')) printf("\t��ʾ:����,���ܽ���\n");
	printf("  (3)����Ϊ%s\n", (Empty(q) ? "��" : "�ǿ�"));
	if (DeQueue(q, e) == 0)
		printf("�ӿ�,���ܳ���\n");
	else
		printf("  (4)����һ��Ԫ��%c\n", e);
	printf("  (5)���ν�����Ԫ��d,e,f\n");
	if (!EnQueue(q, 'd')) printf("\t��ʾ:����,���ܽ���\n");
	if (!EnQueue(q, 'e')) printf("\t��ʾ:����,���ܽ���\n");
	if (!EnQueue(q, 'f')) printf("\t��ʾ:����,���ܽ���\n");
	printf("  (6)����������:");
	while (!Empty(q))
	{
		DeQueue(q, e);
		printf("%c ", e);
	}
	printf("\n");
	
}