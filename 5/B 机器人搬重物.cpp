#include<iostream>
#include<queue>

using namespace std;
struct node {
	int x, y, pos, step;
};
int n, m, vis[51][51][4], map[51][51];
int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0};
int sx, sy, ex, ey, po;
queue<node> q;

bool check(int x, int y, int pos) {
	if (x < 1 || x + 1 > n || y < 1 || y + 1 > m || map[x][y] == 1)
		return false;
	if (map[x][y] || map[x + 1][y] || map[x][y + 1] || map[x + 1][y + 1])
		return false;
	return true;
}

void bfs() {
	q.push({sx, sy, po, 0});
	while (!q.empty()) {
		node p = q.front();
		q.pop();
		if (p.x == ex && p.y == ey) {
			cout << p.step;
			return;
		}
		if (vis[p.x][p.y][p.pos])
			continue;
		vis[p.x][p.y][p.pos] = 1;
		p.step++;
		int pos = (p.pos + 1) % 4;
		q.push({p.x, p.y, pos, p.step});
		pos = (p.pos + 3) % 4;
		q.push({p.x, p.y, pos, p.step});
		int px = p.x, py = p.y;
		for (int i = 1; i <= 3; ++i) {
			px += mx[p.pos];
			py += my[p.pos];
			if (check(px, py, p.pos))
				q.push({px, py, p.pos, p.step});
			else break;
		}
	}
	cout << -1;

}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> map[i][j];
	char ch;
	cin >> sx >> sy >> ex >> ey >> ch;
	switch (ch) {
		case 'E':
			po = 0;
			break;
		case 'S':
			po = 1;
			break;
		case 'W':
			po = 2;
			break;
		case 'N':
			po = 3;
			break;
	}
	bfs();
	return 0;
}