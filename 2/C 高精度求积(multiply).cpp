/* 高精度求积(multiply)
描述
输入两个高精度正整数 M 和 N（M 和 N 均小于 100 位）。求这两个高精度数的积。
输入
共两行，每行一个整数
输出
两个整数的积 */
#include<iostream>
#include<cstring>
using namespace std;
void str2int(char *s,int *a) {
	int l=strlen(s);
	for(int i=l-1; i>=0; --i) {
		a[i]=s[l-1-i]-'0';
	}
}
int main() {
	char s1[101],s2[101];
	int a[100]= {0},b[100]= {0},c[200]= {0},la,lb,lc;
	cin>>s1;
	la=strlen(s1);
	cin>>s2;
	lb=strlen(s2);
	str2int(s1,a);
	str2int(s2,b);
	lc=la+lb;
	for(int i=0; i<lb; ++i) {
		for(int j=0; j<la; ++j) {
			c[j+i]+=a[j]*b[i];
			if(c[j+i]>=10) {
				c[j+i+1]+=c[j+i]/10;
				c[j+i]%=10;
			}
		}
	}
	while(c[lc-1]==0&&lc)
		lc--;
	if(lc==0)
		cout<<"0";
	for(int i=lc-1; i>=0; --i)
		cout<<c[i];
	return 0;
}
