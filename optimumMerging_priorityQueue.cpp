#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int a[] = { 10,10,20,30 };

int main() {
	priority_queue<int, vector<int>, greater<int> > q(a,a+4);
	while (q.size() >=2 ) {
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
		q.push(x + y);
	}
	cout << q.top();
	cin.get();
}