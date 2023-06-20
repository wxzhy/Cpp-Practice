/* 数字三角形
描述
给一个数字三角形，第一层有1个数字，第二层两个，以此类推。从顶端开始，每次可以选择往左下还是右下走，直到走到底部，求一种走的方法，使得路径上的数字和最大。
输入
第一行一个正整数n，表示层数（n<=1000）
接下来n行表示数字三角形，第i行有i个正整数（均不大于10000）
输出
一行一个整数表示最大的路径和 */
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	vector<vector<int>> a(1001, vector<int>(1001));
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> a[i][j];
	for (int i = n - 1; i >= 1; --i)
		for (int j = 1; j <= i; ++j)
			a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
	cout << a[1][1];
	return 0;

}