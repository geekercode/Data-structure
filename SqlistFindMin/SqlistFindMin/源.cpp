#include<iostream>  
using namespace std;
typedef int ElemType;
struct sqList
{
	int length;
	int *data;
};
bool Del_Min(sqList &L, ElemType &value)
{
	//ɾ��˳���L����СֵԪ�ؽڵ㣬��ͨ�������Ͳ���value����ֵ  
	//���ɾ���ɹ�������true�����򣬷���false  
	if (L.length == 0)return false;//��գ���ֹ����   
	value = L.data[0];
	int pos = 0;
	for (int i = 1; i<L.length; i++)//ѭ����Ѱ�Ҿ�����Сֵ��Ԫ��   
	{
		if (L.data[i]<value)      //��value���׵�ǰ������Сֵ��Ԫ��   
		{
			value = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length - 1];//�ճ���λ�������һ��Ԫ���  
	L.length--;
	for (int i = 0; i<L.length; i++)cout << L.data[i] << " ";
	return true;
}
int main()
{
	int value;
	sqList L;
	L.length = 10;
	int a[10] = { 12,10,9,8,7,-3,1,2,4,5 };
	L.data = a;
	Del_Min(L, value);
	cout << endl;
	cout << "min:" << value << endl;
}