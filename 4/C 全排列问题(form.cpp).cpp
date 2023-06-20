/* 全排列问题(form.cpp)
描述
输出自然数 1 到 n 所有不重复的排列，即 n 的全排列，要求所产生的任一数字序列中不允许出现重复的 数字。
输入
n(1≤n≤9)
输出
由 1～n 组成的所有不重复的数字序列，每行一个序列。
同一行的两个数字之间用一个空格隔开。 */
#include<iostream>
using namespace std;
int a[51]= {0},n=0;
bool check(int k) {
	for(int i=1; i<=k-1; ++i)
		if(a[k]==a[i])
			return false;
	return true;
}
void dfs(int k) {
	if(k>n) {
		cout<<a[1];
		for(int i=2; i<=n; ++i)
			cout<<" "<<a[i];
		cout<<endl;
	} else {
		for(a[k]=1; a[k]<=n; ++a[k])
			if(check(k))
                dfs(k + 1);
	}
}
int main() {
	cin>>n;
    dfs(1);
	return 0;
}
