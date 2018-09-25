/*************************************************************************
	> File Name: P1618.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月25日 星期二 16时01分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int valid(int x, int y, int z) {
    int num[10] = {1, 0};
    while (x) {
        if (num[x % 10]) return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    while (y) {
        if (num[y % 10]) return 0;
        num[y % 10] = 1;
        y /= 10;
    }
    while (z) {
        if (num[z % 10]) return 0;
        num[z % 10] = 1;
        z /= 10;
    }
    return 1;
}

int main() {
    int a, b, c, flag = 0;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 100; i < 1000; i++) {
        for (int j = i * b / a - 1; j < 1000; j++) {
            for (int k = i * c / a - 1; k < 1000; k++) {
                if (i * b != j * a) continue;
                if (i * c != k * a) continue;
                if (j * c != k * b) continue;
                if (!valid(i, j, k)) continue;
                flag = 1;
                printf("%d %d %d\n", i, j, k);
            }
        }
    }
    if (flag == 0) {
        printf("No!!!\n");
    }
    return 0;
}
