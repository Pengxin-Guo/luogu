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
int n;
int index[MAX_N + 5];
double ans = 0x3f3f3f3f;

void init() {
    for (int i = 0; i <= n; i++) index[i] = i;
    return ;
}

void func() {
    double temp = 0.0;
    for (int i = 0; i < n; i++) {
        int id1 = index[i], id2 = index[i + 1];
        temp += sqrt((arr[id1].x - arr[id2].x) * (arr[id1].x - arr[id2].x) + (arr[id1].y - arr[id2].y) * (arr[id1].y - arr[id2].y));
    }
    ans = min(ans, temp);
    return ;
}

int main() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    do {
        func();
    } while (next_permutation(index + 1, index + 1 + n));
    printf("%.2f\n", ans);
    return 0;
}
