#include<iostream>  
using namespace std;
typedef int ElemType;
struct sqList
{
	int length;
	int *data;
};
bool Merge(sqList A, sqList B, sqList &C) {
	if (A.length + B.length > C.length)
		return false;
	int i = 0, j = 0, k = 0;
	while (i < A.length&&j < B.length)
	{
		if (A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while (i < A.length)
		C.data[k++] = A.data[i++];
	while (j < B.length)
		C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}
int main() {
	sqList A, B, C;
	A.length = 4;
	B.length = 4;
	C.length = 9;
	int a[4] = { 1,3,5,8 };
	int b[4] = { 2,4,6,10 };
	C.data = new int[10];
	A.data = a;
	B.data = b;
	Merge(A, B, C);
	for (int i = 0; i<C.length; i++)
		cout << C.data[i] << " ";
}
