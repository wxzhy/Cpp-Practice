/* 字符统计
描述
输入一串字符，以#作为结束标志，统计这串字符中英文字母、数字和其它字符的个数
输入
输入数据为若干个字符，以#作为输入结束的标志
输出
分别输出英文字母个数，数字个数，和其它字符个数，每两个数字之间用一个空格隔开
#不统计 */
#include<iostream>
using namespace std;
int main() {
	char s[1000];
	int a = 0, b = 0, c = 0;
	cin.getline(s,1000);
	for (char* p = s; *p != '\0'; ++p) {
		if (isalpha(*p))
			a++;
		else if (isdigit(*p))
			b++;
		else if (*p != '#')
			c++;
		else
			break;
	}
	cout << a << ' ' << b << ' ' << c;
	return 0;
}