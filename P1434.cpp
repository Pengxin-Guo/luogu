/*************************************************************************
	> File Name: P1434.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月14日 星期日 19时49分04秒
 ************************************************************************/
// 有一组数据TLE了

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100

typedef struct Node {
    int x, y, step;
} Node;
int r, c;
int maze[MAX_N + 5][MAX_N + 5];
int vis[MAX_N + 5][MAX_N + 5];
int ans = 0;

int in(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

void bfs(int i, int j) {
    int vis1[MAX_N + 5][MAX_N + 5] = {0};
    queue<Node> q;
    q.push({i, j, 1});
    while (!q.empty()) {
        Node n1 = q.front();
        int x = n1.x, y = n1.y, step = n1.step;
        if (ans < step) ans = step;
        q.pop();
        vis[x][y] = 1;
        if (in(x, y + 1) && maze[x][y + 1] < maze[x][y]) q.push({x, y + 1, step + 1});
        if (in(x, y - 1) && maze[x][y - 1] < maze[x][y]) q.push({x, y - 1, step + 1});
        if (in(x + 1, y) && maze[x + 1][y] < maze[x][y]) q.push({x + 1, y, step + 1});
        if (in(x - 1, y) && maze[x - 1][y] < maze[x][y]) q.push({x - 1, y, step + 1});
    }
    return ;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vis[i][j]) continue;
            bfs(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
