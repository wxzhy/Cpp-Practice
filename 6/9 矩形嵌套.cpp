/* 矩形嵌套
描述
有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成一行，使得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。
输入
第一行是一个正整数n，表示含有矩形的个数(n<=1000)
随后的n行，每行有两个数a,b(0<a,b<=10000)，表示矩形的长和宽
输出
输出一个数，表示最多符合条件的矩形数目 */
#include<iostream>
using namespace std;
int main() {
	int n, a[1001] = {0}, b[1001] = {0}, c[1001] = {0}, m;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];
	for (int i = 1; i <= n; ++i) {
		m = 0;
		for (int j = 1; j < i; ++j)
			if ((a[j] < a[i] && b[j] < b[i]) || (a[j] < b[i] && b[j] < a[i]))
				m = max(c[j], m);
		c[i] = m + 1;
	}
	m = 0;
	for (int i = 1; i <= n; ++i)
		m = max(c[i], m);
	cout << m;
	return 0;
}