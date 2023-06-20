/* 导弹拦截
描述
某国为了防御敌国的导弹袭击，开发出一种导弹拦截系统，但是这种拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭，由于该系统还在试用阶段。所以一套系统有可能不能拦截所有的导弹。
输入导弹依次飞来的高度（雷达给出的高度不大于30000的正整数）。计算要拦截所有导弹最小需要配备多少套这种导弹拦截系统。
输入
n颗依次飞来的高度（1≤n≤1000）.
输出
要拦截所有导弹最少需要配备的系统数量k。 */
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	vector<int> v,j;
	while(cin>>t)
		v.push_back(t);
	for(auto &i:v) {
		if(j.empty()) {
			j.push_back(i);
		} else {
			for(auto &s:j) {
				if(i<=s) {
					s=i;
					goto end;
				}
			}
			j.push_back(i);
		}
	end:
		continue;
	}
	cout<<j.size();
	return 0;
}