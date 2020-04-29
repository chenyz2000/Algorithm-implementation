#include<ctime>
#include<iostream>
using namespace std;

// CLOCKS_PER_SEC=1000，不除以的时候显示的是毫秒

int main() {
	long long sum = 0;
	for (double i = 0; i < 5e7; i++)sum += i;
	cout << (double)clock() / CLOCKS_PER_SEC<<endl;
	for (double i = 0; i < 5e7; i++)sum += i;
	cout << (double)clock() / CLOCKS_PER_SEC;
	cout<<CLOCKS_PER_SEC;
	cin.get();
}