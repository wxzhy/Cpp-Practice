/* 迷宫问题(migong)
描述
设有一个 N*N(2<=N<20)方格的迷宫，入口和出口分别在左上角和右上角。迷宫格子中 分别放 0 和 1，
0 表示可通，1 表示不能通过，入口和出口处肯定是 0。
迷宫走的规则如下所示：
即从某点开始，有八个方向可走，前进方格中数字为 0 时表示可通过，为 1 时表示不可通过， 要另找路径。
找出所有从入口（左上角）到出口（右上角）的路径(不能重复)，输出路径总数，如果无法到达，则输出 0。
输入
第一行一个整数n
接下来n行每行n个数字，仅包含0或1，用来描述迷宫
输出
仅一行，从入口到出口的路径总数 */
#include<iostream>
using namespace std;
int path[21][21]= {0},in[21][21]= {0},n,c=0;
bool check(int i,int j) {
    if(i<1||i>n||j<1||j>n)
        return false;
    if(in[i][j] || path[i][j])
        return false;
    return true;
}
void dfs(int a, int b) {
    if(a==1&&b==n) {
        c++;
    } else {
        for(int i=a-1; i<=a+1; i++)
            for(int j=b-1; j<=b+1; j++)
                if(check(i,j)) {
                    path[i][j]=1;
                    dfs(i, j);
                    path[i][j]=0;
                }
    }
}
int main() {
    cin>>n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin >> in[i][j];
    path[1][1]=1;
    dfs(1, 1);
    cout<<c;
    return 0;
}
