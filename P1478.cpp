/*************************************************************************
	> File Name: P1478.cpp
	> Author: gpx 
	> Mail: 1457495424@qq.com 
	> Created Time: 2018年09月10日 星期一 21时26分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MAX 5000

using namespace::std;

typedef struct apple{
    int x;
    int y;
}apple;

apple app[MAX + 5];

int cmp(apple a1, apple a2) {
    return a1.y < a2.y;
}

int main() {
    int n, s, a, b, ans = 0;
    scanf("%d%d%d%d", &n, &s, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &app[i].x, &app[i].y);
    }
    sort(app, app + n, cmp);
    for (int i = 0; i < n; i++) {
        if (s < app[i].y) break;
        if (app[i].x <= (a + b) && s >= app[i].y) {
            ans += 1;
            s -= app[i].y;
        }
    }
    printf("%d\n", ans);
    return 0;
}
