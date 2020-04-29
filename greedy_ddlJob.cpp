#include<iostream>
#include<algorithm>
using namespace std;

struct job {int p, d;};
job a[7] = { {0}, {3, 1}, { 8,3 }, { 20,4 }, { 6,2 }, { 7,1 }, { 5,2 } };

int main() {
	sort(a+1, a+7, [](job x, job y)->bool {return x.p > y.p; });
	int res[7] = { 0,1 }, k = 1;//a[1]绝对能放入res中，所以res[1]=1；k为res中已放入的工作个数
	for (int i = 2; i < 7; i++) {
		int t = k;
		//寻找插入点，要满足插入点后部所有工作的d都大于工作i的d，且后部所有工作右移一位以后d不超限（第t位的上限d是t）
		while (a[res[t]].d > a[i].d&&a[res[t]].d >= t+1) { t--; }

		//判断是否能够插入
		//如果第一个条件不成立就说明第t个工作不能右移（即不满足while的第二个条件）；第二个条件说明工作i放入t+1位时d不超限
		if (a[res[t]].d <= a[i].d&&a[i].d >= t+1) {
			for (int j = k; j < t + 1; j--)res[j + 1] = res[j];
			res[t + 1] = i;
			k++;
		}

	}
	for (int i = 0; i < 7; i++)cout << res[i] << ' ';
	cin.get();
}
