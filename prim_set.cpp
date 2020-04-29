//prim是针对点进行回路判定，O(n^2)，适合稀疏图、动态规划
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

//点称作整数还是字母本质上是一样的
struct Edge { int e; char x, y; };
struct Edge E[9] = { {10,'a','b'},{5,'b','d'},{2,'a','c'},{1,'c','g'},{7,'c','d'},{3,'c','e'},{1,'e','d'},{5,'e','f'},{8,'d','f'} };
set<char> s;
int sum;
void init() {
	sort(E, E + 9, [](Edge x, Edge y)->bool {return x.e < y.e; });
	s.insert(E[0].x);
	s.insert(E[0].y);
	sum = E[0].e;//或者就在里面定义,static int sum =E[0].e
}

int prim(Edge *E) {
	//O(|V|^2),与边数无关
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {
			if (s.count(E[j].x) + s.count(E[j].y) == 1){
				s.insert(E[j].x);
				s.insert(E[j].y);
 				sum+=E[j].e;
				break;//一定要break
			}
		}
		//每走一个循环，得重新遍历E
	}
	return sum;
}

int main() {
	init();
	printf("%d", prim(E));
	system("pause");
}