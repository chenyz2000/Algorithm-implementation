#include<iostream>
#include<ctime>
#include<random>
using namespace std;

int a[101] = { 0 };
const int all = sizeof(a) / 4 - 1;
const int r = 7;//每组有7个元素
const int s = all / r;//共有s组

void insertionSort(int m, int n) {
	for (int i = m + 1; i <= n; i++) {
		int t = a[i];
		int j = i - 1;
		while (a[j]>t&&j>=m) {
			a[j + 1] = a[j]; j--;
		}
		a[j + 1] = t;
	}
}

int partition(int m, int n) {
	int t = a[m], i = m, j = n + 1;
	do {
		do { i++; } while (a[i] < t);
		do { j--; } while (a[j] > t);
		if (i < j) { int k = a[i]; a[i] = a[j]; a[j] = k; }
	} while (i < j);
	a[m] = a[j]; a[j] = t;
	return j;
}

void mid(int m, int n) {//将中值放到数组前部
	for (int i = 1; i <= s; i++) {
		insertionSort(r * (i-1)+1,r * i+1);//用n^2排序就行了,注意左右开闭,sort是左开右闭
		int t = a[r * i - r / 2]; a[r * i - r / 2] = a[i]; a[i] = t;//交换到数组前部
		cout << t << ' ';
	}
	//二次取中
	insertionSort(1, s+1);
	cout << endl;
	int t = a[1 + s / 2]; a[1 + s / 2] = a[1]; a[1] = t;
	cout << t<<endl<<endl;
}

int select(int m, int n, int k) {
	if (n - m + 1 <= r) {
		insertionSort(n, m);
		return a[k];
	}
	while (1) {
		int j = partition(m, n);
		if (k == j)return a[j];
		else if (k < j)n = j - 1;
		else m = j + 1;
	}
}

void init() {
	int t = time(NULL);
	for (int i = 1; i <= 100; i++) {
		srand(t - 100 * i);
		a[i] = rand() % 300;
	}
}
void print() {
	int count = 0;
	for (int i = 1; i <= 100; i++) {
		printf("%-5d", a[i]);
		count++;
		if (count % 10 == 0)printf("\n");
	}
}

int main() {
	init();
	mid(1,100);
	print();
	cout << select(1, 100, 1) << " " << select(1, 100, 2) << " " << select(1, 100, 3) << " " << select(1, 100, 4) << " " << select(1, 100, 5);
	cin.get();
}