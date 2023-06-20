/* 装箱问题(boxes)
描述
有一个箱子容量为 v（正整数，0≤v≤20000），同时有 n 个物品（0<n≤30），每个物品 有一个体积（正整数）。 要求从 n 个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
输入
箱子的容量 v     物品数 n
接下来 n 行，分别表示这 n 个物品的体积
输出
箱子剩余空间 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int v, n, a[31] = {0};
	vector<vector<int>> f(31, vector<int>(20001, 0));
	cin >> v;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= v; ++j)
			if (j < a[i])
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + a[i]);
	cout << v - f[n][v];
	return 0;
}