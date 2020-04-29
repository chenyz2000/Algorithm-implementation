//krusckal是针对边进行回路判定
#include<iostream>
#include<algorithm>
using namespace std;

//还是用整数索引更好，不然par[]和rank[]索引得char-97

struct Edge { int e, x, y; };
struct Edge E[9] = { {10,0,1},{5,1,3},{2,0,2},{1,2,6},{7,2,3},{3,2,4},{1,4,3},{5,4,5},{8,3,5} };
int par[9];
int rank[9];
int sum;

void init() {
	sort(E, E + 9, [](Edge i, Edge j)->bool {return i.e < j.e; });
	for (int i = 0; i < 9; i++) par[i] = i;
	sum = E[0].e;
	par[E[0].x] = E[0].y;
}

char find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (::rank[x] < ::rank[y]) par[x] = y;
	else {
		par[y] = x;
		if (::rank[x] == ::rank[y]) ::rank[x]++;
	}
}
bool same(int x, int y) {
	return find(x)==find(y);
}

int kruskal(Edge *E) {
	for (int i = 0; i < 9; i++) {
		if (!same(E[i].x, E[i].y)) {
			sum = E[i].e+sum;
			unite(E[i].x, E[i].y);
		}
	}
	return sum;
}

int main() {
	init();
	printf("%d", kruskal(E));
	system("pause");
}