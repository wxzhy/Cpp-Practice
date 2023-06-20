/* 逃亡的准备(hallows)
描述
在《Harry Potter and the Deathly Hallows》中，Harry Potter他们一起逃亡，现 在有许多的东西要放到赫敏的包里面，但是包的大小有限，所以我们只能够在里面放入非常 重要的物品，现在给出该种物品的数量、体积、价值的数值，希望你能够算出能使背包的价值最大的组合方式，并且输出这个数值，赫敏会非常地感谢你。
输入
第一行有 2 个整数，物品种数 n 和背包装载体积 v。 2 行到 i+1 行每行 3 个整数，为第 i 种物品的数量 m、体积 w、价值 s。
输出
包含一个整数，即为能拿到的最大的物品价值总和。 */
#include<iostream>
using namespace std;
int n, v;
int m[2001], w[2001], s[2001];
int f[2][2001];
int &F(int x, int y) {
	return f[x % 2][y];
}
int main() {
	cin >> n >> v;
	for (int i = 1; i <= n; ++i) {
		cin >> m[i] >> w[i] >> s[i];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= v; ++j) {
			for (int k = 0; k <= m[i]; ++k) {
				if (k * w[i] > j) break;
				else
					F(i,j)= max(F(i,j), F(i-1,j-k*w[i])+k*s[i]);
			}
		}
	cout<<F(n,v);
	return 0;
}
