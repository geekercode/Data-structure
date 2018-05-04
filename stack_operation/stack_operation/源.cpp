//文件名:algo3-1.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;					//栈顶指针
} SqStack;
void InitStack(SqStack *&s)		//初始化栈S
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;					//栈顶指针置为-1
}
void DestroyStack(SqStack *&s)	//销毁栈s
{
	free(s);
}
bool StackEmpty(SqStack *s)		//判断栈空
{
	return(s->top == -1);
}
bool Push(SqStack *&s, ElemType e)	//进栈
{
	if (s->top == MaxSize - 1)	//栈满的情况，即栈上溢出
		return false;
	s->top++;				//栈顶指针增1
	s->data[s->top] = e;		//元素e放在栈顶指针处
	return true;
}
bool Pop(SqStack *&s, ElemType &e)	//出栈
{
	if (s->top == -1)		//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];	//取栈顶指针元素的元素
	s->top--;			//栈顶指针减1
	return true;
}
bool GetTop(SqStack *s, ElemType &e)		//取栈顶元素
{
	if (s->top == -1)		//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];	//取栈顶指针元素的元素
	return true;
}
void main()
{
	ElemType e;
	SqStack *s;
	printf("栈s的基本运算如下:\n");
	printf("  (1)初始化栈s\n");
	InitStack(s);
	printf("  (2)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (3)依次进栈元素a,b,c,d,e\n");
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	printf("  (4)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (5)出栈序列:");
	while (!StackEmpty(s))
	{
		Pop(s, e);
		printf("%c ", e);
	}
	printf("\n");
	printf("  (6)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (7)释放栈\n");
	DestroyStack(s);
}
