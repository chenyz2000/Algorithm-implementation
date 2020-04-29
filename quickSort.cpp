#include<iostream>
#include<ctime>
#include<random>
using namespace std;

int a[101] = {0};//本程序都使用闭区间[1,100]
const int INF = 100000;

int partition(int m,int n) {//划分闭区间[m,n]
	//划分元素先视为a[m]
	int t = a[m], i = m, j = n+1;//下面的j--决定初始值为n+1，如果划分元素不是a[m]的话m要变成m-1?
	do {
		do { i++; } while (a[i] < t);//都无等号
		do { j--; } while (a[j] > t);
		if (i < j) { int k; k=a[i]; a[i] = a[j]; a[j] = k; }//换位，这一步没写对过
	} while (i < j);//无等号
	a[m] = a[j]; a[j] = t;
	return j;//返回划分元素最终的下标位置
}

void quickSortRec(int m,int n) {
	if (m < n) {//无等号
		int j = partition(m, n);
		quickSortRec(m, j-1);
		quickSortRec(j + 1, n);
	}
}

void init() {
	int t = time(NULL);
	for (int i = 1; i <= 100; i++) {
		srand(t - 100*i);
		a[i] = rand()%300;
	}
	a[101] = INF;
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
	quickSortRec(1, 100);
	print();
	cin.get();
}