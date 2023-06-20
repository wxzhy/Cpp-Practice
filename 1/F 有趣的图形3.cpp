/* 有趣的图形3
描述
输入两个整数m和n，输出以m和n分别为长和宽的由*围成的空心矩形
输入
输入仅一行，包含两个整数，m和n，0<m,n<=2.1*10^9
输出
输出m行n列的，由*围成的矩形 */
#include<iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cout << '*';
	cout << endl;
	if (m == 1)
		return 0;
	for (int i = 1; i <= m - 2; i++) {
		cout << "*";
		for (int j = 1; j <= n - 2; j++)
			cout << ' ';
		cout << "*";
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
		cout << '*';
	cout << endl;
	return 0;
}