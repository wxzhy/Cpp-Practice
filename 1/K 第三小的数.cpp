/* 第三小的数
描述
输入一组数字，输出这些数字中第三小的数。
输入
第一行一个整数n，代表数字的总数。n<2.1*10^10
接下来n行，每行一个数字
输出
输出n个数字中第三小的数 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n,t;
 	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	cout << a[2];
	return 0;
}