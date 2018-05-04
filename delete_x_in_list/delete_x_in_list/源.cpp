#include<iostream>  
using namespace std;
typedef int ElemType;
struct sqList
{
	int length;
	int *data;
};
void delx(sqList &L, ElemType x) {
	int k = 0;     //记录值不等于x的个数
	for (int i = 0; i < L.length; i++)
		if (L.data[i] != x) {
			L.data[k] = L.data[i];
			k++;
		}

	for (int j = 0; j < k; j++) {
		cout << L.data[j] << " ";
	}
	cout << endl;
	cout << "the repeated number is " << L.length-k;
}
int main() {
	sqList L;
	int x = 2;
	L.length = 10;
	int a[10] = { 1,2,2,2,3,5,8,6,9,4 };
	L.data = a;
	delx(L, x);
}