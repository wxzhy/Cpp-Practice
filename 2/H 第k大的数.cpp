/* 第k大的数
描述
输入n个不同的正整数，保证每个正整数都不超出整型表示范围，输出其中第k大的数字
输入
输入第一行为连个数字，n和k，0<n,k<2.1*10^9
接下来n行每行一个正整数
输出
输出第k大的数字 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n,t,k;
	vector<int> v;
	cin>>n>>k;
	for(int i=0; i<n; ++i) {
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),greater<int>());
	cout<<v[k-1];
	return 0;
}
