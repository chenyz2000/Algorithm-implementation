#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>&a,int n) {//vector����&�������������//int ����&Ҳ���Բ���
	//n�����ⲿ����Ҳ�����ڲ�д�������ڲ���&��ʱ��������n�����ָ�룬n=1
	//��������������Ϊ1~n
	for (int i = 2; i <= n; i++) {
		a[0] = a[i];//�����ڣ�����ʡȥ��ѭ����ÿ�ζ�j>=0���жϣ��൱������ʱ����
		int j = i - 1;
		while (a[j] > a[0]) {
			a[j + 1] = a[j]; j--;
		}
		a[j + 1] = a[0];
	}
}

int main() {
	vector<int>a;
	a.push_back(0);
	int t;
	while (1) {//���벻��������
		scanf("%d", &t);
		a.push_back(t);
		if (getchar() == '\n') break;
	}
	int n = a.size()-1;
	insertionSort(a,n);
	for (int i = 1; i <= n; i++) cout << a[i]<<' ';//��Ϊ�����Ҫn,���ԾͲ��ں�������n��
	system("pause");
}