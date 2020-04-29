#include<iostream>
#include<algorithm>
using namespace std;

struct sim {
	int a, b;
}s[4] = { {100,2},{10,1},{15,2},{20,1} };

//运算符重载1
//bool operator<(const sim i, const sim j) {return i.a < j.a;}
//可以不加const

//运算符重载2
//struct node {
//	int a, b;
//	bool operator< (const node &x) { return a < x.a; }
//};

//比较函数
//bool cmp(const sim i, const sim j) {return i.a < j.a;}

//lambda
//[](const sim i, const sim j) ->bool{return i.a < j.a; }

int main() {
	sort(s, s + 4);
	for (int i = 0; i < 4; i++) cout << s[i].a << " ";
	cout << '\n';
	for (int i = 0; i < 4; i++) cout << s[i].b << " ";
	system("pause");
}