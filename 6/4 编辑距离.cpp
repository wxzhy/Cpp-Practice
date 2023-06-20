/* 编辑距离
描述
设A和B是两个字符串（仅包含小写字母）。求最少的字符操作次数，即编辑距离，将字符串A转换为字符串B。这里所说的字符操作共有三种：
◦删除一个字符；
◦插入一个字符；
◦将一个字符改为另一个字符。
输入
两行各一个仅包含小写字母的字符串，且长度均小于1000
输出
输出它们的编辑距离 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
	char a[1001] = " ", b[1001] = " ";
	int m, n;
	vector<vector<int>> f(1000, vector<int>(1000, 10000));
	cin >> (a + 1);
	cin >> (b + 1);
	n = strlen(a);
	m = strlen(b);
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		f[i][0] = i;
	for (int j = 1; j <= m; ++j)
		f[0][j] = j;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			f[i][j] = min(f[i - 1][j - 1] + bool(a[i] != b[j]), f[i][j]);
		}
	cout << f[n][m];
	return 0;
}