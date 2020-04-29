//线性插入排序(insertion sort)
#include<iostream>
using namespace std;

void insertionSort(int a[], int n) {
	//int n = sizeof(a) / sizeof(int);
	//value above is 1, but lenth of array if written in main() .
	//because data passed to parameter is not array but pointer;
	for (int i = 1; i < n; i++) {
		int t = a[i], j = i - 1;
		while (t < a[j]) {
			a[j + 1] = a[j];
			j -= 1;
		}
		a[j + 1] = t;
	}
}

int main() {
	int a[] = { 2,35,-42,10,9,4,71,16,0,-10 };
	int n = sizeof(a) / sizeof(int);
	insertionSort(a, n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	system("pause");
}