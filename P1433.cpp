/*************************************************************************
	> File Name: P1433.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月15日 星期一 20时35分07秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX_N 15

typedef struct Node {
    double x, y;
}Node;

Node arr[MAX_N + 5];
double dis[MAX_N + 5][MAX_N + 5];
int n;
int vis[MAX_N + 5];
double ans = 0x3f3f3f3f;

void init() {
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    // 预处理一下点与点之间的距离
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dis[i][j] = sqrt((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
        }
    }
    return ;
}

void dfs(int step, int now, double length) {
    if (length > ans) {    // 剪枝
        return ;
    }
    if (step == n) {
        ans = min(ans, length);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(step + 1, i, length + dis[now][i]);
            vis[i] = 0;
        }
    }
    return ;
}

int main() {
    cin >> n;
    init();
    dfs(0, 0, 0.0);
    printf("%.2f\n", ans);
    return 0;
}
