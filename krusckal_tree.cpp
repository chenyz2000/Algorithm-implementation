#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Edge { int e, x, y; };
struct Edge E[9] = { {10,0,1},{5,1,3},{2,0,2},{1,2,6},{7,2,3},{3,2,4},{1,4,3},{5,4,5},{8,3,5} };//	之后要改为用邻接矩阵或邻接表来写
int par[9] ;
vector <vector<int> > T;
int sum;

int find(int x) {
	while (par[x] > 0) {
		x = par[x];
	}
	return x;
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;

	int t = par[x] + par[y];
	if (par[x] < par[y]) { par[x] = t; par[y] = x; }
	else { par[y] = t; par[x] = y; }
}

void krusckal() {
	for (int i = 0; i < 9; i++) { par[i] = -1; }
	sort(E, E + 9, [](Edge i, Edge j)->bool {return i.e < j.e; });
	int count = 0;
	for (int i = 0; i < 9; i++) {//如果T是数组，得考虑路径在T中的索引用什么表示
		int u = find(E[i].x), v = find(E[i].y);
		if (u != v) {
			T.push_back({ E[i].x,E[i].y });
			sum += E[i].e;
			unite(u, v);
			count++;
		}
	}
	if (count != 6)sum = -1;//6是点数减1
}


int main() {
	krusckal();
	cout << sum << endl;
	system("pause");
}