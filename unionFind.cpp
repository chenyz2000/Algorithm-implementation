//并查集union-find
#include<iostream>
using namespace std;

int par[10];
//int rnk[10];		//rnk初始化为0
void initpar() {
	for (int i = 0; i < 10; i++) {par[i] = i;}
}

int find(int x) {
	return (par[x] == x) ? x : par[x]=find(par[x]);//这里一个赋值就实现了路径压缩
}

void unite(int x, int y) {
	//两个阶段
	a = find(x); b = find(y);
	par[x] = a; par[y] = b;
	if (a == b) return;

	/*if (rnk[a] < rnk[b]) par[a] = b;
	else {
		par[b] = a;
		if (rnk[a] == rnk[b]) a++;
	}		//秩优化
	*/
}

bool same(int x, int y) {
	return par[x] == par[y] ? true : false;
}

int main() {

}