/*************************************************************************
	> File Name: P1003.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月05日 星期五 20时57分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int num[MAX + 5][4] = {0};

int main() {
    int n, a, b, g, k, x, y, ans = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &a, &b, &g, &k);
        num[i][0] = a;
        num[i][1] = b;
        num[i][2] = g;
        num[i][3] = k;
    }
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; i++) {
        if (x >= num[i][0] && x <= num[i][0] + num[i][2] && y >= num[i][1] && y <= num[i][1] + num[i][3]) ans = i;
    }
    printf("%d\n", ans);
    return 0;
}
