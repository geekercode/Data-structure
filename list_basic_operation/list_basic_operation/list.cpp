#include <stdio.h>
#include <malloc.h>
#include "list.h"

//�����鴴�����Ա�
void CreateList(SqList *&L, ElemType a[], int n)
{
	int i;
	L = (SqList *)malloc(sizeof(SqList));
	for (i = 0; i<n; i++)
		L->data[i] = a[i];
	L->length = n;
}

//��ʼ�����Ա�InitList(L)
void InitList(SqList *&L)   //������ָ��
{
	L = (SqList *)malloc(sizeof(SqList));
	//���������Ա�Ŀռ�
	L->length = 0;
}

//�������Ա�DestroyList(L)
void DestroyList(SqList *&L)
{
	free(L);
}

//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
bool ListEmpty(SqList *L)
{
	return(L->length == 0);
}

//�����Ա�ĳ���ListLength(L)
int ListLength(SqList *L)
{
	return(L->length);
}

//������Ա�DispList(L)
void DispList(SqList *L)
{
	int i;
	if (ListEmpty(L)) return;
	for (i = 0; i<L->length; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}

//��ĳ������Ԫ��ֵGetElem(L,i,e)
bool GetElem(SqList *L, int i, ElemType &e)
{
	if (i<1 || i>L->length)  return false;
	e = L->data[i - 1];
	return true;
}

//��Ԫ��ֵ����LocateElem(L,e)
int LocateElem(SqList *L, ElemType e)
{
	int i = 0;
	while (i<L->length && L->data[i] != e) i++;
	if (i >= L->length)  return 0;
	else  return i + 1;
}

//��������Ԫ��ListInsert(L,i,e)
bool ListInsert(SqList *&L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1)
		return false;   //��������ʱ����false
	i--;            //��˳����߼����ת��Ϊ�������
	for (j = L->length; j>i; j--) //��data[i..n]Ԫ�غ���һ��λ��
		L->data[j] = L->data[j - 1];
	L->data[i] = e;           //����Ԫ��e
	L->length++;            //˳�������1
	return true;            //�ɹ����뷵��true
}

//ɾ������Ԫ��ListDelete(L,i,e)
bool ListDelete(SqList *&L, int i, ElemType &e)
{
	int j;
	if (i<1 || i>L->length)  //��������ʱ����false
		return false;
	i--;        //��˳����߼����ת��Ϊ�������
	e = L->data[i];
	for (j = i; j<L->length - 1; j++) //��data[i..n-1]Ԫ��ǰ��
		L->data[j] = L->data[j + 1];
	L->length--;              //˳����ȼ�1
	return true;              //�ɹ�ɾ������true
}