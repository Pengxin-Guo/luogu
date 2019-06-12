/*************************************************************************
	> File Name: P1605.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月12日 星期三 20时31分56秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 5
#define MAX_M 5

int maze[MAX_N + 5][MAX_M + 5], vis[MAX_N + 5][MAX_M + 5];
int n, m, t, sx, sy, fx, fy, cnt = 0;

int in(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        cnt += 1;
    }
    vis[x][y] = 1;
    if (in(x + 1, y) && !vis[x + 1][y]) dfs(x + 1, y);
    if (in(x - 1, y) && !vis[x - 1][y]) dfs(x - 1, y);
    if (in(x, y + 1) && !vis[x][y + 1]) dfs(x, y + 1);
    if (in(x, y - 1) && !vis[x][y - 1]) dfs(x, y - 1);
    vis[x][y] = 0;
    return ;
}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    while (t--) {
        int a, b;
        cin >> a >> b;
        vis[a][b] = 1;
    }
    dfs(sx, sy);
    cout << cnt << endl;
    return 0;
}
