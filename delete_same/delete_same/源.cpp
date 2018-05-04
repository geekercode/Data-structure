#include<iostream>  
using namespace std;
typedef int ElemType;
struct sqList
{
	int length;
	int *data;
};
bool delete_same(sqList &L) {
	if (L.length == 0)
		return false;
	int i, j;
	for (i = 0,j = 1; j < L.length; j++)
		if (L.data[i] != L.data[j])
			L.data[++i] = L.data[j];
	L.length = i + 1;
}
int main() {
	sqList L;
	L.length = 11;
	int a[11] = { 1,2,2,2,2,3,3,3,4,4,5 };
	L.data = a;
	delete_same(L);
	for (int i = 0; i<L.length; i++)
		cout << L.data[i] << " ";
   

}