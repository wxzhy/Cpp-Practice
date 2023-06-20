#include<iostream>
#include<queue>

using namespace std;
struct node {
	int x, y;
};
queue<node> q;
int n, a[31][31];
int mx[] = {-1, 1, 0, 0}, my[] = {0, 0, -1, 1};

bool check(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > n)
		return false;
	if (a[x][y] == 1 || a[x][y] == -1)
		return false;
	return true;
}

void bfs(int x, int y) {
	q.push({x, y});
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		if (!check(t.x, t.y))
			continue;
		a[t.x][t.y] = -1;
		for (int i = 0; i < 4; ++i) {
			q.push({t.x + mx[i], t.y + my[i]});
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++) {
		bfs(1, i);
		bfs(i, 1);
		bfs(n, i);
		bfs(i, n);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == -1)
				cout << 0 << " ";
			else if (a[i][j] == 0)
				cout << 2 << " ";
			else
				cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}