/*************************************************************************
	> File Name: P1162.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月18日 星期二 19时07分37秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 30

int maze[MAX_N + 5][MAX_N + 5];
int n;
int vis[MAX_N + 5][MAX_N + 5];

typedef struct Node {
    int x, y;
} Node;

int in(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

int is_valid(int i, int j) {
   memset(vis, 0, sizeof(vis)); 
    queue<Node> q;
    Node n1 = {i, j};
    vis[i][j] = 1;
    q.push(n1);
    while (!q.empty()) {
        Node temp = q.front();
        int x = temp.x, y = temp.y;
        if (x == 1 || x == n || y == 1 || y == n) return 0;        // 如果0出现在边界, 则返回0
        q.pop();
        if (in(x + 1, y) && !vis[x + 1][y] && !maze[x + 1][y]) q.push({x + 1, y}), vis[x + 1][y] = 1;
        if (in(x - 1, y) && !vis[x - 1][y] && !maze[x - 1][y]) q.push({x - 1, y}), vis[x - 1][y] = 1;
        if (in(x, y + 1) && !vis[x][y + 1] && !maze[x][y + 1]) q.push({x, y + 1}), vis[x][y + 1] = 1;
        if (in(x, y - 1) && !vis[x][y - 1] && !maze[x][y - 1]) q.push({x, y - 1}), vis[x][y - 1] = 1;
    }
    return 1;
}

void bfs(int i, int j) {
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    Node n1 = {i, j};
    vis[i][j] = 1;
    q.push(n1);
    while (!q.empty()) {
        Node temp = q.front();
        int x = temp.x, y = temp.y;
        maze[x][y] = 2;
        q.pop();
        if (in(x + 1, y) && !vis[x + 1][y] && !maze[x + 1][y]) q.push({x + 1, y}), vis[x + 1][y] = 1;
        if (in(x - 1, y) && !vis[x - 1][y] && !maze[x - 1][y]) q.push({x - 1, y}), vis[x - 1][y] = 1;
        if (in(x, y + 1) && !vis[x][y + 1] && !maze[x][y + 1]) q.push({x, y + 1}), vis[x][y + 1] = 1;
        if (in(x, y - 1) && !vis[x][y - 1] && !maze[x][y - 1]) q.push({x, y - 1}), vis[x][y - 1] = 1;
    }
    return ;
}

void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            j == 1 || cout << " ";
            cout << maze[i][j];
        }
        cout << endl;
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> maze[i][j];
        }
    }
    int flag = 1;
    for (int i = 1; i <= n && flag; i++) {
        for (int j = 1; j <= n && flag; j++) {
            if (maze[i][j]) continue;
            if (is_valid(i, j)) {
                flag = 0;
                bfs(i, j);
            }
        }
    }
    if (flag) {
        bfs(2, 2);
    }
    output();
    return 0;
}
