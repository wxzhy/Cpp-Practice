/* 水仙花数
描述
如果一个三位数ABC，满足A^3+B^3+C^3=ABC，则称这个数为水仙花数。例如153=1^3+5^3+3^3，所以153是水仙花数
编程找出给定范围内的所有的三位水仙花数
输入
输入仅一行，包含两个数字m,n，两个数字用空格隔开，切保证m和n都是三位数，m<=n。
输出
按从小到大顺序输出所有的三位水仙花数，每个数字一行。如果给定范围内没有水仙花数，输出NOANSWER! */
#include<iostream>
using namespace std;
int main() {
	int m, n,count=0;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		int a=i/100,b=(i%100)/10,c=i%10;
		if(a*a*a+b*b*b+c*c*c==i) {
			cout<<i<<endl;
			count++;
		}
	}
	if(!count)
		cout<<"NOANSWER!";
	return 0;
}