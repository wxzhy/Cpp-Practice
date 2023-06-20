/* 金明的预算方案(budget)
描述

金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间金明自己专用的很宽 敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置， 你说了算，只要不超过 N 元钱就行”。今天一早，金明就开始做预算了，他把想买的物品分 为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有 0 个、1 个 或 2 个附件。附件不再有从属于自己的附件。金明想买的东西很多，肯定会超过妈妈限定的 N 元。于是，他把每件物品规定了一个重要度，分为 5 等：用整数 1~5 表示，第 5 等最重要。 他还从因特网上查到了每件物品的价格（都是 10 元的整数倍）。他希望在不超过 N 元（可以 等于 N 元）的前提下，使每件物品的价格与重要度的乘积的总和最大。 设第j件物品的价格为v[j]，重要度为w[j]，共选中了k件物品，编号依次为j1，j2，……， jk，则所求的总和为： v[j1]*w[j1]+v[j2]*w[j2]+ …+v[jk]*w[jk]。（其中*为乘号） 请你帮助金明设计一个满足要求的购物单。
输入
输入文件 budget.in 的第 1 行，为两个正整数，用一个空格隔开： N  m   （其中 N（<32000）表示总钱数，m（<60）为希望购买物品的个数。） 从第 2 行到第 m+1 行，第 j 行给出了编号为 j-1 的物品的基本数据，每行有 3 个非负整 数：  v  p  q （其中 v 表示该物品的价格（v<10000），p 表示该物品的重要度（1~5），q 表示该物品 是主件还是附件。如果 q=0，表示该物品为主件，如果 q>0，表示该物品为附件，q 是所属 主件的编号）
输出
输出文件 budget.out 只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的 总和的最大值（<200000）。 */
#include<iostream>
using namespace std;
int main() {
	int n, m;
	int f[32001] = {0};
	int value[60][3] = {0}, weight[60][3] = {0};
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int v, p, q;
		cin >> v >> p >> q;
		if (!q) {
			value[i][0] = v * p;
			weight[i][0] = v;
		} else if (!value[q][1]) {
			value[q][1] = v * p;
			weight[q][1] = v;
		} else {
			value[q][2] = v * p;
			weight[q][2] = v;
		}
	}
	for(int i=1; i<=m; ++i)
		for(int j=n; j>=weight[i][0]; --j) {
			if (j - weight[i][0] >= 0)
				f[j] = max(f[j], f[j - weight[i][0]] + value[i][0]);
			if (j - weight[i][0] - weight[i][1] >= 0)
				f[j] = max(f[j], f[j - weight[i][0] - weight[i][1]] + value[i][0] + value[i][1]);
			if (j - weight[i][0] - weight[i][2] >= 0)
				f[j] = max(f[j], f[j - weight[i][0] - weight[i][2]] + value[i][0] + value[i][2]);
			if (j - weight[i][0] - weight[i][1] - weight[i][2] >= 0)
				f[j] = max(f[j], f[j - weight[i][0] - weight[i][1] - weight[i][2]] + value[i][0] + value[i][1] + value[i][2]);

		}
	cout << f[n];
	return 0;
}