/* 整数倒序2
描述
输入一个整数，将这个数字的各个位上的数字取出，倒序后组成一个新的数字，输出这个新数。
输入
输入数据仅一行，包含一个整数n。0<=n<=2.1*10^9
输出
输出仅一行，为将整数n倒序后组成的新的数字。 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	while (*(s.end()-1) == '0') {
		s.pop_back();
	}
	reverse(s.begin(), s.end());
	cout << s;
	return 0;
}