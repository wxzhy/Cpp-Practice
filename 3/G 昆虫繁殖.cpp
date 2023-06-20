/* 昆虫繁殖
描述
科学家在热带森林中发现了一种特殊的昆虫，这种昆虫的繁殖能力很强。每对成虫过x个月产y对卵，每对卵要过两个月长成成虫。假设每个成虫不死，第一个月只有一对成虫，且卵长成成虫后的第一个月不产卵(过X个月产卵)，问过Z个月以后，共有成虫多少对？
0=<X<=20,1<=Y<=20,X=<Z<=50
输入
x,y,z的数值
输出
过Z个月以后，共有成虫对数 */
#include <iostream>
using namespace std;
int main() {
	long long a[101]= {0},b[101]= {0};
	int x,y,z;
	cin>>x>>y>>z;
	for(int i=0; i<=x; i++) {
		a[i]=1;
		b[i]=0;
	}
	for(int i=1+x; i<=z+1; i++) {
		b[i]=y*a[i-x];
		a[i]=a[i-1]+b[i-2];
	}
	cout<<a[z+1];
	return 0;
}