/* 马的遍历
描述
有⼀个n*m的棋盘，在某个(x,y) 上有⼀个马，要求你计算出马到达棋盘上任意⼀个点最少要⾛⼏步。
输入
输⼊只有⼀⾏四个整数，分别为n，m，x，y
输出
⼀个n*m的矩阵，代表马到达某个点最少要⾛⼏步（不能到达则输出 -1）
为统一输出的格式，输出的矩阵中的每个元素占用的宽度总计为5且左对齐，除数字外的部分使用空格。
提示：可使用printf("%-5d", xxx)；来输出结果矩阵中的每个元素。 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct node {
	int x, y, pos;
};
queue<node> q;
int n, m, x, y;
bool path[500][500];
int c[500][500];
int mx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int my[] = {2, -2, 1, -1, 2, -2, 1, -1};

bool check(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m)
		return false;
	if (path[x][y])
		return false;
	return true;
}

void bfs(int x, int y) {
	q.push({x, y, 0});
	path[x][y] = true;
	c[x][y] = 0;
	while (!q.empty()) {
		node p = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int px = p.x + mx[i], py = p.y + my[i], pos = p.pos + 1;
			if (check(px, py)) {
				path[px][py] = true;
				q.push({px, py, pos});
				c[px][py] = pos;
			}
		}
	}
}
int main() {
	memset(c,-1,sizeof(c));
	cin>>n>>m>>x>>y;
	bfs(x,y);
	for(int i=1; i<=n; ++i) {
		for (int j = 1; j <= m; ++j)
			printf("%-5d", c[i][j]);
		cout<<endl;
	}
	return 0;
}