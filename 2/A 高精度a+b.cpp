/* 高精度a+b
描述
输入两个数a和b，输出a+b的值
输入
输入共两行，分别为证书a,b
0<=a,b<=10^100
输出
输出a+b的值 */
#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char s[101];
	int a[100]= {0},b[100]= {0},c[101]= {0},la,lb,lc;
	cin>>s;
	la=strlen(s);
	for(int i=la-1; i>=0; --i) {
		a[i]=s[la-1-i]-'0';
	}
	cin>>s;
	lb=strlen(s);
	for(int i=lb-1; i>=0; --i) {
		b[i]=s[lb-1-i]-'0';
	}
	lc=la>lb?la:lb;
	for(int i=0; i<lc; i++) {
		c[i]+=a[i]+b[i];
		if(c[i]>=10) {
			c[i]-=10;
			c[i+1]++;
		}
	}
	if(c[lc]>0)
		lc++;
	for(int i=lc-1; i>=0; --i)
		cout<<c[i];
	return 0;



}
