#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
struct node {
	int x, y, pos;
};
int v[405][405];
int ans[405][405];
int main()
{
	int n, m, sx, sy;
	queue <node> q;
	cin >> n >> m >> sx >> sy;
	q.push({ sx,sy,0 });
	v[sx][sy] = 1;
	int wx[9] = { 0,1,1,2,2,-1,-1,-2,-2 };
	int wy[9] = { 0,2,-2,1,-1,2,-2,1,-1 };
	while (!q.empty())
	{
		int x = q.front().x, y = q.front().y, pos = q.front().pos;
		q.pop();
		for (int i = 1; i <= 8; i++)
		{
			int dx = x + wx[i], dy = y + wy[i];
			if (dx > 0 && dy > 0 && dx <= n && dy <= m && !v[dx][dy])
			{
				v[dx][dy] = 1;
				q.push({ dx,dy,pos + 1 });
				ans[dx][dy] = pos + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			if (i == sx && j == sy)
				cout <<left<< setw(5) << 0;
			else
				cout <<left<< setw(5) << (ans[i][j] ? ans[i][j] : -1);
		cout << endl;
	}
	return 0;
}