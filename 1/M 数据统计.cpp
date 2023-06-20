/* 数据统计
描述
输入一些整数，求出它们的最小值、最大值和平均值（保留3位小数）。输入保证这些数都是不超过1000的整数。
输入
输入仅一行，包含若干个数字。输入的数字至多不超过10000个，保证每个数字不超过1000、且所有数字的和不超过整型的表示范围。
输出
输出这些数字中的最大值、最小值，以及平均值（保留三位小数）。数字之间用空格隔开。 */
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int a[1000],n=0;
	char c;
	do {
		cin>>a[n++];
		cin.get(c);
	} while(c==' ');
	double min=a[0],max=a[0],sum=a[0];
	for(int i=1; i<n; i++) {
		min=a[i]<min?a[i]:min;
		max=a[i]>max?a[i]:max;
		sum+=a[i];
	}
	sum/=n;
	cout<<min<<' '<<max<<' '<<setprecision(3)<<fixed<<sum;
	return 0;
}