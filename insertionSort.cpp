#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>&a,int n) {//vector不加&不会带出操作？//int 不加&也可以操作
	//n可以外部导入也可以内部写，但是在不加&的时候函数内算n算的是指针，n=1
	//数组中数字索引为1~n
	for (int i = 2; i <= n; i++) {
		a[0] = a[i];//监视哨，可以省去内循环中每次对j>=0的判断，相当于是临时变量
		int j = i - 1;
		while (a[j] > a[0]) {
			a[j + 1] = a[j]; j--;
		}
		a[j + 1] = a[0];
	}
}

int main() {
	vector<int>a;
	a.push_back(0);
	int t;
	while (1) {//输入不定长数据
		scanf("%d", &t);
		a.push_back(t);
		if (getchar() == '\n') break;
	}
	int n = a.size()-1;
	insertionSort(a,n);
	for (int i = 1; i <= n; i++) cout << a[i]<<' ';//因为输出需要n,所以就不在函数内算n辽
	system("pause");
}