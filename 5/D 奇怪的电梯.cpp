/* 奇怪的电梯
描述
呵呵有⼀天我做了⼀个梦，梦见了⼀种很奇怪的电梯。⼤楼的每⼀层楼都可以停电梯，⽽且第 i 层楼（ 1<=i<=N）上有⼀个数字 Ki（ 0<=Ki<=N ）。
电梯只有四个按钮：开，关，上，下。上下的层数等于当前楼层上的那个数字。当然，如果不能满⾜要求，相应的按钮就会失灵。
例如：3 3 1 2 5 代表了 Ki（ K1=3，K2=3 ，……），从 1 楼开始。在1楼按“上”可以到 4 楼，按“下”是不起作⽤的，因为没有 -2 楼。那么，从 A 楼到 B 楼⾄少要按⼏次按钮呢？
输入
共⼆⾏。
第⼀⾏为三个⽤空格隔开的正整数，表⽰ N，A，B（1<=N<-200 ，1<=A,B<=N ）。
第⼆⾏为 个⽤空格隔开的⾮负整数，表⽰ 。
输出
⼀⾏，即最少按键次数，若⽆法到达，则输出-1 */
#include<iostream>
#include<queue>
using namespace std;
struct button {
	int floor, count;
};
queue<button> q;
int n, a, b, s[201];
bool v[201];

bool check(int x) {
	if (x < 1||x>n)
		return false;
	if(v[x])
		return false;
	return true;
}
void bfs() {
	q.push({a, 0});
	while (!q.empty()) {
		button t = q.front();
		q.pop();
		if (t.floor == b) {
			cout<<t.count;
			return;
		}
		if (check(t.floor + s[t.floor])) {
			q.push({t.floor + s[t.floor], t.count + 1});
			v[t.floor + s[t.floor]] = true;
		}
		if (check(t.floor - s[t.floor])) {
			q.push({t.floor - s[t.floor], t.count + 1});
			v[t.floor - s[t.floor]] = true;
		}
	}
	cout<<-1;
}
int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	bfs();
	return 0;
}