/*************************************************************************
	> File Name: P1141.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月18日 星期二 20时47分41秒
 ************************************************************************/
// TLE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_N 1000

char maze[MAX_N + 5][MAX_N + 5];
int n, m;
int vis[MAX_N + 5][MAX_N + 5];
int map[MAX_N + 5][MAX_N + 5];
int ans[MAX_N * MAX_N + 5];

typedef struct Node {
    int x, y;
} Node;

int in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs(int id, int i, int j) {
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push({i, j});
    vis[i][j] = 1;
    map[i][j] = id;
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        int x = temp.x, y = temp.y;
        map[x][y] = id;
        cnt++;
        if (maze[x][y] == '0') {
            if (in(x + 1, y) && !vis[x + 1][y] && maze[x + 1][y] == '1') vis[x + 1][y] = 1, q.push({x + 1, y});
            if (in(x - 1, y) && !vis[x - 1][y] && maze[x - 1][y] == '1') vis[x - 1][y] = 1, q.push({x - 1, y});
            if (in(x, y + 1) && !vis[x][y + 1] && maze[x][y + 1] == '1') vis[x][y + 1] = 1, q.push({x, y + 1});
            if (in(x, y - 1) && !vis[x][y - 1] && maze[x][y - 1] == '1') vis[x][y - 1] = 1, q.push({x, y - 1});
        } else {
            if (in(x + 1, y) && !vis[x + 1][y] && maze[x + 1][y] == '0') vis[x + 1][y] = 1, q.push({x + 1, y});
            if (in(x - 1, y) && !vis[x - 1][y] && maze[x - 1][y] == '0') vis[x - 1][y] = 1, q.push({x - 1, y});
            if (in(x, y + 1) && !vis[x][y + 1] && maze[x][y + 1] == '0') vis[x][y + 1] = 1, q.push({x, y + 1});
            if (in(x, y - 1) && !vis[x][y - 1] && maze[x][y - 1] == '0') vis[x][y - 1] = 1, q.push({x, y - 1});
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    int id = 1;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (vis[x - 1][y - 1] == 0) {
            ans[id] = bfs(id, x - 1, y - 1);
            id++;
        }
        cout << ans[map[x - 1][y - 1]] << endl;
    }
    return 0;
}
