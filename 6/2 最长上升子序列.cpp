/* 最长上升子序列
描述
现给出n个整数，求出最长的上升子序列的长度。
注：
1.子序列指的是从这n个数中选取若干个不同的数（没有其他要求），按原来的顺序组成的序列
2.上升序列指的是一个序列的后一项总是大于前面一项
输入
第一行一个正整数n表示序列长度（n<=1000）
第二行n个正整数a_i，均不大于10000
输出
一行一个整数表示最长上升子序列的长度 */
#include<iostream>
using namespace std;
int main() {
	int n, a[1001] = {0}, b[1001] = {0}, m;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		m = 0;
		for (int j = 1; j < i; ++j)
			if (a[j] < a[i])
				m = max(b[j], m);
		b[i] = m + 1;
	}
	m = 0;
	for (int i = 1; i <= n; ++i)
		m = max(b[i], m);
	cout << m;
	return 0;
}