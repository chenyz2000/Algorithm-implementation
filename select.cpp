#include<iostream>
#include<ctime>
#include<random>
using namespace std;

int a[101] = {0};

int partition(int m, int n) {
	int t = a[m], i = m, j = n+1;
	do {
		do { i++; } while (a[i] < t);
		do { j--; } while (a[j] > t);
		if (i < j) { int k = a[i]; a[i] = a[j]; a[j] = k; }
	} while (i < j);
	a[m] = a[j]; a[j] = t;
	return j;
}

int select(int m,int n,int k) {
	while (1) {
		int j = partition(m, n);
		if (k == j)return a[j];
		else if (k < j)n = j-1;
		else m = j + 1;
	}
	//或者写if return;else if return ;else return;递归形式
}

void init() {
	int t = time(NULL);
	for (int i = 1; i <= 100; i++) {
		srand(t - 100*i);
		a[i] = rand()%300;
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
	print();
	cout << select(1, 100, 1) << " " << select(1, 100, 2) << " " << select(1, 100, 3) << " " << select(1, 100, 4) << " " << select(1, 100, 5);
	cin.get();
}