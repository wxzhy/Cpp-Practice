/* N 皇后问题(queen.cpp)
描述
在 N*N 的棋盘上放置 N 个皇后（n<50）而彼此不受攻击（即在棋盘的任一行，任一列和任一对角线上 不能放置 2 个皇后），编程求解所有的摆放方法。
输入
输入：n
输出
每行输出一种方案，每种方案顺序输出皇后所在的列号，各个数之间有空格隔开。若无方案，则输出 no solute! */
#include<iostream>
#include<cmath>
using namespace std;
int a[51]= {0},c=0,n=0;
bool check(int k) {
	for(int i=1; i<=k-1; ++i)
		if(a[k]==a[i]||abs(a[k]-a[i])==k-i)
			return false;
	return true;
}
void queen(int k) {
	if(k>n) {
		c++;
		cout<<a[1];
		for(int i=2; i<=n; ++i)
			cout<<" "<<a[i];
		cout<<endl;
	} else {
		for(a[k]=1; a[k]<=n; ++a[k])
			if(check(k))
				queen(k+1);
	}
}
int main() {
	cin>>n;
	queen(1);
	if(!c)
		cout<<"no solute!";
	return 0;
}