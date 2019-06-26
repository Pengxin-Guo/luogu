/*************************************************************************
	> File Name: P1443.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月26日 星期三 20时43分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_N 400

int maze[MAX_N + 5][MAX_N + 5];
int vis[MAX_N + 5][MAX_N + 5];
int n, m, sx, sy;
typedef struct Node {
    int x, y, cnt;
} Node;

int in(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs(int i, int j) {
    queue<Node> q;
    Node pre = {i, j, 0};
    q.push(pre);
    vis[i][j] = 1;
    while (!q.empty()) {
        Node n1 = q.front();
        q.pop();
        int x = n1.x, y = n1.y, cnt = n1.cnt;
        maze[x][y] = cnt;
        if (in(x + 2, y + 1) && !vis[x + 2][y + 1]) vis[x + 2][y + 1] = 1, q.push({x + 2, y + 1, cnt + 1});
        if (in(x + 2, y - 1) && !vis[x + 2][y - 1]) vis[x + 2][y - 1] = 1, q.push({x + 2, y - 1, cnt + 1});
        if (in(x - 2, y + 1) && !vis[x - 2][y + 1]) vis[x - 2][y + 1] = 1, q.push({x - 2, y + 1, cnt + 1});
        if (in(x - 2, y - 1) && !vis[x - 2][y - 1]) vis[x - 2][y - 1] = 1, q.push({x - 2, y - 1, cnt + 1});
        if (in(x + 1, y + 2) && !vis[x + 1][y + 2]) vis[x + 1][y + 2] = 1, q.push({x + 1, y + 2, cnt + 1});
        if (in(x + 1, y - 2) && !vis[x + 1][y - 2]) vis[x + 1][y - 2] = 1, q.push({x + 1, y - 2, cnt + 1});
        if (in(x - 1, y + 2) && !vis[x - 1][y + 2]) vis[x - 1][y + 2] = 1, q.push({x - 1, y + 2, cnt + 1});
        if (in(x - 1, y - 2) && !vis[x - 1][y - 2]) vis[x - 1][y - 2] = 1, q.push({x - 1, y - 2, cnt + 1});
        pre = n1;
    }
    return ;
}

void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cout << maze[i][j];
            printf("%-5d", maze[i][j]);
        }
        cout << endl;
    }
    return ;
}

int main() {
    memset(maze, -1, sizeof(maze));
    cin >> n >> m >> sx >> sy;
    bfs(sx, sy);
    output();
    return 0;
}
