/* 第 k 小整数(knumber)
描述
现有 n 个正整数，n≤10000，要求出这 n 个正整数中的第 k 个最小整数（相同大小的整数只计算一次）， k≤1000，正整数均小于 30000。
输入
第一行为 n 和 k，第二行开始为 n 个正整数的值，整数间用空格隔开。
输出
第 k 个最小整数的值；若无解，则输出“NO  RESULT”。 */
#include<iostream>
#include<set>
using namespace std;
int main() {
	int n,k,t;
	set<int> s;
	cin>>n>>k;
	for(int i=1; i<=n; ++i) {
		cin>>t;
		s.insert(t);
	}
	t=0;
	for(auto &i:s) {
		t++;
		if(t==k) {
			cout<<i;
			return 0;
		}
	}
	cout<<"NO RESULT";
	return 0;
}
