/* 高精度a-b
描述
输入两个数字a,b，计算a-b的值
输入
共两行，每行一个整数，即a,b
0<=a,b<=10^100
输出
输出仅一行，为a-b的值 */
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
	int a[100]= {0},b[100]= {0},c[100]= {0},la,lb,lc,sym=1;
	cin>>s1;
	la=strlen(s1);
	cin>>s2;
	lb=strlen(s2);
	if(la>lb) {
		str2int(s1,a);
		str2int(s2,b);
	} else if(la==lb&&strcmp(s1,s2)>=0) {
		str2int(s1,a);
		str2int(s2,b);
	} else {
		str2int(s1,b);
		str2int(s2,a);
		sym=-1;
	}
	lc=la>lb?la:lb;
	for(int i=0; i<lc; ++i) {
		c[i]+=a[i]-b[i];
		if(c[i]<0) {
			c[i+1]--;
			c[i]+=10;
		}
	}
	while(c[lc-1]==0&&lc) {
		lc--;
	}
	if(sym==-1)
		cout<<'-';
	for(int i=lc-1; i>=0; --i)
		cout<<c[i];
	if(lc==0)
		cout<<"0";
	return 0;

}
