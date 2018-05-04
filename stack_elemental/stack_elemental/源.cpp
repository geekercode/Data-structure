#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef  char elemtype;
typedef struct
{
	elemtype data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack *&s)  //��ʼ��ջ
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}
bool StackEmpty(SqStack *s)
{
	return(s->top == -1);
}
void DestroyStack(SqStack *&s)
{
	free(s);
}
bool Push(SqStack *&s,elemtype e) //��ջ
{
	if (s->top == MaxSize - 1)
		return false;
	
	s->data[++s->top] = e;
	return true;
}
bool Pop(SqStack *&s, elemtype &e) //��ջ
{
	if (s->top == -1)
		return false;
	e = s->data[s->top--];
	return true;
}
bool GetTop(SqStack *s, elemtype &e)		//ȡջ��Ԫ��
{
	if (s->top == -1)		//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];	//ȡջ��ָ��Ԫ�ص�Ԫ��
	return true;
}
void main()
{
	elemtype e;
	SqStack *s;
	InitStack(s);
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	GetTop(s, e);
	printf("%c\n", e);
	/*while (!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c\n",e);
		
	}*/
}