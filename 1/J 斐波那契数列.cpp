/* 斐波那契数列
描述
斐波那切数列 1， 1， 2， 3， 5， 8， 13， 21， 34， 55……从第三项起，每一项都是前两项的和。
写出计算斐波那切数列的任意一个数据项递归程序。
输入
输入所求的项数n。
输出
输出斐波那契数列第n项的值 */
#include<iostream>
using namespace std;
int fabs(int x) {
	if(x==1||x==2)
		return 1;
	else
		return fabs(x-1)+fabs(x-2);
}
int main() {
	int n;
	cin>>n;
	cout<<fabs(n);
	return 0;
}
