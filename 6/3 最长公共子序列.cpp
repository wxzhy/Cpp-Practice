/* 最长公共子序列
描述
给出两个序列P1​和P2，长度分别为n，m​，求它们的最长公共子序列。
公共子序列指的是在两者中均出现的子序列。
输入
第一行两个正整数n和m表示两个序列的长度（n,m<=1000）
第二行和第三行分别是两个序列的内容，每个数均为不大于10000的正整数
输出
一行一个整数表示最长公共子序列的长度 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, p1[1001], p2[1001];
	vector<vector<int>> f(1001, vector<int>(1001, 0));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> p1[i];
	for (int i = 1; i <= m; i++)
		cin >> p2[i];
	for (int i = 1; i <= n; i++) {
		f[i][0] = 0;
	}
	for (int j = 1; j <= m; j++) {
		f[0][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			f[i][j] = max(f[i - 1][j - 1] + bool(p1[i] == p2[j]), f[i][j]);
		}
	}
	cout << f[n][m];
	return 0;
}