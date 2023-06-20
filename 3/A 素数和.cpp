/* 素数和
描述
给定一个区间范围[m,n]，输出该区间内所有素数的和
输入
本题有多组输入数据
每组数据一行，包含两个数字m,n。
0<=m,n<=10^5
输出
对每一组输入数据，输出[m,n]区间内所有素数的和 */
#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n) {
	if(n==1||n==0)
		return false;
	for(int i=2; i<=sqrt(n); ++i) {
		if(n%i==0)
			return false;
	}
	return true;
}
int sum(int m,int n) {
	int sum=0;
	for(int i=m; i<=n; ++i)
		if(isprime(i))
			sum+=i;
	return sum;
}
int main() {
	int m,n;
	while(cin>>m>>n) {
		cout<<sum(m,n)<<endl;
	}
	return 0;
}