//�ļ���:algo3-1.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;					//ջ��ָ��
} SqStack;
void InitStack(SqStack *&s)		//��ʼ��ջS
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;					//ջ��ָ����Ϊ-1
}
void DestroyStack(SqStack *&s)	//����ջs
{
	free(s);
}
bool StackEmpty(SqStack *s)		//�ж�ջ��
{
	return(s->top == -1);
}
bool Push(SqStack *&s, ElemType e)	//��ջ
{
	if (s->top == MaxSize - 1)	//ջ�����������ջ�����
		return false;
	s->top++;				//ջ��ָ����1
	s->data[s->top] = e;		//Ԫ��e����ջ��ָ�봦
	return true;
}
bool Pop(SqStack *&s, ElemType &e)	//��ջ
{
	if (s->top == -1)		//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];	//ȡջ��ָ��Ԫ�ص�Ԫ��
	s->top--;			//ջ��ָ���1
	return true;
}
bool GetTop(SqStack *s, ElemType &e)		//ȡջ��Ԫ��
{
	if (s->top == -1)		//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];	//ȡջ��ָ��Ԫ�ص�Ԫ��
	return true;
}
void main()
{
	ElemType e;
	SqStack *s;
	printf("ջs�Ļ�����������:\n");
	printf("  (1)��ʼ��ջs\n");
	InitStack(s);
	printf("  (2)ջΪ%s\n", (StackEmpty(s) ? "��" : "�ǿ�"));
	printf("  (3)���ν�ջԪ��a,b,c,d,e\n");
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	printf("  (4)ջΪ%s\n", (StackEmpty(s) ? "��" : "�ǿ�"));
	printf("  (5)��ջ����:");
	while (!StackEmpty(s))
	{
		Pop(s, e);
		printf("%c ", e);
	}
	printf("\n");
	printf("  (6)ջΪ%s\n", (StackEmpty(s) ? "��" : "�ǿ�"));
	printf("  (7)�ͷ�ջ\n");
	DestroyStack(s);
}
