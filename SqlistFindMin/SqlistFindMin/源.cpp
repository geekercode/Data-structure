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
	//删除顺序表L中最小值元素节点，并通过引用型参数value返回值  
	//如果删除成功，返回true；否则，返回false  
	if (L.length == 0)return false;//表空，终止操作   
	value = L.data[0];
	int pos = 0;
	for (int i = 1; i<L.length; i++)//循环，寻找具有最小值的元素   
	{
		if (L.data[i]<value)      //让value极易当前具有最小值的元素   
		{
			value = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length - 1];//空出的位置由最后一个元素填补  
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