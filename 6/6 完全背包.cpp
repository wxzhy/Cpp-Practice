/* 完全背包
描述
有n个物品，每个物品有一个体积vi和价值ci且可以取无数次，从中取出一些装到容量为m的背包中，求最大可能总价值。
输入
第一行两个正整数n和m分别表示物品的个数和背包的容量（n,m<=1000）
接下来n行，每行两个正整数vi和ci表示物品的体积和价值（vi<=100,ci<=10000）
输出
输出最大能获得的总价值 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n, m, v[1001] = {0}, c[1001] = {0};
	vector<vector<int>> f(1001, vector<int>(1001, 0));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> v[i] >> c[i];
	for (int i = 0; i <= n; ++i)
		f[i][0] = 0;
	for (int j = 0; j <= m; ++j)
		f[0][j] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (j - v[i] < 0)
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + c[i]);
	cout << f[n][m];
	return 0;
}