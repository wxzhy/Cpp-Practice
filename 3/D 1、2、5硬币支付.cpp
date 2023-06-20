/* 1、2、5硬币支付
描述
某人带了三种面值的硬币出门购物，面值分别时1元、2元、5元
已知购物总金额为m元，求至少需要使用多少枚硬币可以恰好支付m元
输入
一个整数m，m<2.1*10^9
输出
一个整数，即最少使用的硬币个数 */
#include<iostream>
using namespace std;
int main() {
	int m;
	cin>>m;
	for(int i=m/5; i>=0; i--)
		for(int j=(m-5*i)/2; j>=0; j--)
			for(int k=m-5*i-2*j; k>=0; k--)
				if(i*5+j*2+k==m) {
					cout<<i+j+k;
					return 0;
				}
}