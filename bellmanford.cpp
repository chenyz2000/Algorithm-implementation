//单源最短路，最后获得的是dist数组
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 100000;
const int x = 2;//给定单源点
vector<vector<int> >E = { {0}, {0,0,10,2,INF,INF,INF,INF},{0,10,0,INF,5,INF,INF,INF},{0,2,INF,0,7,3,INF,1 },{0,INF,5,7,0,1,8,INF},{0,INF,INF,3,1,0,5,INF},{0,INF,INF,INF,8,5,0,INF},{0,INF,INF,1,INF,INF,INF,0} };
const int v = E.size() - 1;
vector<int> S;//用来记载访问过的信息
vector<int> dist;//x到某点的距离

void init() {
	for (int i = 0; i <= v; i++) {
		S.push_back(0);
		dist.push_back(E[x][i]);
	}
	S[x] = 1;
	dist[x] = 0;
}

void bellmanford() {
	for (int i = 2; i <= v; i++) {
		int mini = INF, u = 0;
		for (int j = 1; j <= v; j++) {
			if (S[j] == 0 && dist[j] <= mini) {
				mini = dist[j];
				u = j;
			}
		}
		S[u] = 1;
		for (int j = 1; j <= v; j++) {
			dist[j] = min(dist[j], dist[u] + E[u][j]);//x直接到j的距离和x经过u到j的距离
		}//松弛修改距离
	}
}

int main() {
	init();
	bellmanford();
	for (int i = 1; i <= v; i++)cout << dist[i] << ' ';
	cin.get();
}