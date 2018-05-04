#include<stdio.h>
#include<malloc.h>
typedef char elemtype;
typedef struct linknode
{
	elemtype data;
	struct linknode *next;
}LiStack;
void InitStack(LiStack *&s)  //³õÊ¼»¯Õ»
{
	s = (LiStack *)malloc(sizeof(LiStack));
	s->next == NULL;
}
bool Empty(LiStack *s)
{
	return(s->next == NULL);

}
void Push(LiStack *&s, elemtype e)
{
	LiStack *p;
	p = (LiStack*)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
bool Pop(LiStack *&s, elemtype &e)
{
	LiStack *p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
bool GetTop(LiStack *s, elemtype &e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}
void main()
{
	elemtype e;
	LiStack *s;
	InitStack(s);
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'h');
	while (!Empty(s))
	{
		Pop(s, e);
		printf("%c\n", e);
	}
}