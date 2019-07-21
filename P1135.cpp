/*************************************************************************
	> File Name: P1135.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月21日 星期日 20时46分34秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 200

struct Node {
    int id, step;
} node[MAX_N + 5];

int K[MAX_N + 5];
int vis[MAX_N + 5];
int n, a, b, ans = -1;

void bfs(int st, int fi) {
    queue<Node> q;
    q.push({st, 0});
    while (!q.empty()) {
        Node n1 = q.front();
        int id = n1.id, k = K[id], step = n1.step;
        q.pop();
        if (id == fi) {
            ans = step;
            return ;
        }
        if (id + k <= n && vis[id + k]) vis[id + k]--, q.push({id + k, step + 1});
        if (id - k > 0 && vis[id - k]) vis[id - k]--, q.push({id - k, step + 1});
    }
    return ;
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) vis[i] = 1, node[i].id = i, cin >> K[i];
    bfs(a, b);
    cout << ans << endl;
    return 0;
}
