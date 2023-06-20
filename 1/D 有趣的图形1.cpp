/* 有趣的图形1
描述
输入一个整数n，输出n行的由*组成的直角三角形
输入
一个整数n，n<200
输出
n行的由*组成的直角三角形 */
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			cout << "*";
		cout << endl;
	}
	return 0;
}