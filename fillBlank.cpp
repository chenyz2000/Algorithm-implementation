#include<iostream>
using namespace std;

const int m = 20, n =10;
int a[m][n];

int main() {
	int x = 0, y = 0, num = 1;
	a[x][y] = num;
	while (num < m*n) {
		while (y < n - 1 && a[x][y + 1] == 0)a[x][++y] = ++num;
		while (x < m - 1 && a[x + 1][y] == 0) a[++x][y] = ++num;
		while (y > 0 && a[x][y - 1] == 0)a[x][--y] = ++num;
		while (x > 0 && a[x - 1][y] == 0)a[--x][y] = ++num;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%3d ", a[i][j]);
		cout << endl;
	}
	system("pause");
}