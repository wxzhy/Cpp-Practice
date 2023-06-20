/* 整数倒序1
描述
输入一个整数，按倒序输出这个整数各个位上的数字。
输入
输入数据仅一行，包含一个整数n。0<=n<=2.1*10^9
输出
输出仅一行，为倒序的整数n各个位上的数字，每两个数字之间用一个空格间隔开。 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	for (auto& c : s) {
		cout << c<<' ';
	}
	return 0;
}