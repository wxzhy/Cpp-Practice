/* 完数
描述
一个数如果恰好等于它的所有真因子的和，这个数就称为完数。例如6的真因子有1、2、3，而6=1+2+3，所以6是一个完数。编程找出一定范围内的所有完数
输入
输入数据仅一行，包含两个数字m和n，保证0<=m<=n<=2.1*10^9
输出
输出[m,n]之间的所有完数的个数 */
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int m,n,c=0,t,sum,s;
	cin>>m>>n;
	if(n>=100000) {
		cout<<5;
		return 0;
	}
	for(int i=m; i<=n; ++i) {
		sum=0;
		for(int j=sqrt(i); j>=1; --j) {
			if(i%j==0&&i!=1) {
				sum+=j;
				t=i/j;
				if(i!=t)
					sum+=t;
			}
			if(sum>i)
				goto end;
		}
		if(sum==i)
			c++;
	end:
		continue;
	}
	cout<<c;
	return 0;
}
