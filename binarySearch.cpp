//二分检索(binary search)
#include<iostream>
using namespace std;

//x is the num to be searched, and n is the lenth of a[]
//return index of x, or -1 if not exist
int binarySearch(int *a, int x, int n) {
	int low = 0, high = n, mid = n / 2;
	while (low <= high) {
		if (a[mid] == x) return mid;
		else if (x < a[mid]) { high = mid-1; mid = (low + high) / 2; }//low+high may overflow→mid = low+(high-low)/2
		else if (x > a[mid]) { low = mid+1; mid = (low + high) / 2; }
	}
	return -1;
}

int main() {
	int a[] = { 3,4,5,6,7,8 };		//sorted already (binary search is based upon sorting)
	int n = sizeof(a) / sizeof(int);
	printf("%d",binarySearch(a, 4, n));
	system("pause");
}