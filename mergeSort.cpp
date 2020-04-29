#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int a[100], b[100];//a和b数组不用再写到参数里

void merge( int low, int mid,int high) {
	int i=low, j=mid+1, k=low;//对闭区间[low<=mid]和[mid+1<=high]进行合并
	while (i <= mid && j <= high) {
		if (a[i] <= a[j])  b[k++] = a[i++];
		else b[k++] = a[j++]; 
	}
	if (i > mid) while (j <= high) b[k++] = a[j++]; 
	else while (i <= mid) b[k++] = a[i++];

	for (int i = low; i <= high; i++)a[i] = b[i];//将辅助数组b的值copy到a的相应位置
}

void mergeSort(int low,int high) {//排序的下标为开区间[low,high]
	if (low < high) {
		//递归是：若划分区间超过1个元素则继续划分，若只有一个元素则返回向上进行两个区间的合并
		int mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}//之前用while break了，不就是if么，递归都用if
}

void init() {
	int t = time(NULL);
	for (int i = 0; i < 100; i++) {
		srand(t-100*i);//只减i的话，连续运行时，上一次运行的后部和这一次的前部数据相同
		a[i] = rand()%300;
	}
}
void print() {
	int count = 0;
	for (int i = 1; i <= 100; i++) { 
		printf("%-5d", a[i]);
		count++;
		if (count % 10 == 0)printf("\n"); 
	}
}

int main() {
	init();
	mergeSort( 0, 99);
	print();
	cin.get();
}