#include<iostream>
using namespace std;
typedef int Elemtype;
struct sqlist {
	int length;
	int *data;

};
void Reverse(sqlist &L) {
	Elemtype temp;
	for(int i=0;i<L.length/2;i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;

	}
	for (int i = 0; i<L.length; i++)
		cout << L.data[i] << " ";
	return ;
}
int main() {
	sqlist L;
	L.length = 8;
	int a[8] = { 1,2,3,4,5,6,7,9 };
	L.data = a;
	Reverse(L);

}