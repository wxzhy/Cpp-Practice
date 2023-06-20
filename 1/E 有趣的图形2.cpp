/* 有趣的图形2
描述
输入一个整数n，输出2n-1行的由*组成的菱形
输入
一个整数n，n<200
输出
输出2n-1行的由*组成的菱形 */
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++)
			cout << ' ';
		for (int j = 1; j <= 2 * i - 1; j++)
			cout << '*';
		cout << endl;
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = 1; j <= n - i; j++)
			cout << ' ';
		for (int j = 1; j <= 2 * i - 1; j++)
			cout << '*';
		cout << endl;
	}
	return 0;
}