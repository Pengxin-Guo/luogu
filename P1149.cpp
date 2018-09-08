/*************************************************************************
	> File Name: P1149.cpp
	> Author: gpx 
	> Mail: 1457495424@qq.com 
	> Created Time: 2018年09月08日 星期六 21时28分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int valid(int n) {
    if (n < 10) return num[n];
    int a = 0;
    while (n) {
        a += num[n % 10];
        n /= 10;
    }
    return a;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i <= 1111; i++) {
        for (int j = 0; j <= 1111; j++) {
            if (i == j) continue;
            if (valid(i) + valid(j) + valid(i + j) == n - 4) ans += 1;
        }
    }
    for (int i = 0; i <= 1111; i++) {
        if (valid(i) + valid(i) + valid (i + i) == n - 4) ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
