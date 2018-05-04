#pragma once
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
} SqList;
void CreateList(SqList *&L, ElemType a[], int n);//�����鴴�����Ա�
void InitList(SqList *&L);//��ʼ�����Ա�InitList(L)
void DestroyList(SqList *&L);//�������Ա�DestroyList(L)
bool ListEmpty(SqList *L);//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
int ListLength(SqList *L);//�����Ա�ĳ���ListLength(L)
void DispList(SqList *L);//������Ա�DispList(L)
bool GetElem(SqList *L, int i, ElemType &e);//��ĳ������Ԫ��ֵGetElem(L,i,e)
int LocateElem(SqList *L, ElemType e);//��Ԫ��ֵ����LocateElem(L,e)
bool ListInsert(SqList *&L, int i, ElemType e);//��������Ԫ��ListInsert(L,i,e)
bool ListDelete(SqList *&L, int i, ElemType &e);//ɾ������Ԫ��ListDelete(L,i,e)#endif // LIST_H_INCLUDED
#endif