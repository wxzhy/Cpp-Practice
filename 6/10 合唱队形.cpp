/* 合唱队形
描述
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK，则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1≤i≤K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入
输入的第一行是一个正整数n（n<=1000），表示同学的总数。第二行有n个正整数，用空格分隔，第i个整数Ti（Ti<=10000）是第i位同学的身高。
输出
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。 */
#include <iostream>
using namespace std;
int main() {
	int t[1001] = {0}, n, a[1001] = {0}, b[1001] = {0}, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; ++i) {
		m = 0;
		for (int j = 1; j < i; ++j)
			if (t[j] < t[i])
				m = max(m, a[j]);
		a[i] = m + 1;
	}
	for (int i = n; i >= 1; --i) {
		m = 0;
		for (int j = n; j > i; --j)
			if (t[j] < t[i])
				m = max(m, b[j]);
		b[i] = m + 1;
	}
	m = 0;
	for (int i = 1; i <= n; ++i)
		m = max(m, a[i] + b[i] - 1);
	cout << n - m;
	return 0;
}