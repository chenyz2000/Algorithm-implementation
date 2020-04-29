#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<vector<int> > mat;//fill(d.begin(), d.end(), INF);		初始化最短距离，全部为INF
const int INF = 100000;
mat E = { {0}, {0,0,10,2,INF,INF,INF,INF},{0,10,0,INF,5,INF,INF,INF},{0,2,INF,0,7,3,INF,1 },{0,INF,5,7,0,1,5,INF},{0,INF,INF,3,1,0,5,INF},{0,INF,INF,INF,8,5,0,INF},{0,INF,INF,1,INF,INF,INF,0} };
//如果把0改成INF会不会好一点?
//mat E = { {0},{0,0,1,INF,INF,INF},{0,1,0,INF,INF,INF},{0,INF,INF,0,2,4},{0,INF,INF,2,0,3},{0,INF,INF,4,3,0} };//非联通图的一组数据
const int v = E.size()-1;
mat T;

int prim(mat E) {
	int a, b, min = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (E[i][j] < min&&E[i][j]!=0) {
				a = i, b = j, min = E[i][j];
			}
		}
	}
	int sum = min;
	T.push_back({ a,b });//找权最小边

	vector<int> Near;//可以改成char什么的吖
	Near.push_back(0);
	for (int i = 1; i <= v; i++) {
		Near.push_back(E[i][a] < E[i][b] ? a : b);
	}
	Near[a] = Near[b] = 0;
	//初始化near

	for (int k = 0; k < v-2; k++) {//如果T用数组，就要靠k来标记路径在T中的索引
		
		int i0,min=INF;//不能min=Near[1]，少了判断是否为0
		for (int i = 1; i <= v; i++) {
			if (Near[i] != 0 && E[i][Near[i]] <= min) {//小于等于号的等于十分关键，保证i0能得到值（因为循环次数也正好足够）
				min = E[i][Near[i]];
				i0 = i;
			}
		}

		T.push_back({ i0,Near[i0] });
		sum += min;
		Near[i0] = 0;
		for (int i = 1; i <= v; i++) {
			if (Near[i] != 0 && E[i][Near[i]] > E[i][i0]) Near[i] = i0;//更新near
		}
	}

	return (sum >= INF) ?  -1: sum;
}

int main() {
	cout<<prim(E)<<endl;
	system("pause");
}
