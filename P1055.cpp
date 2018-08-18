/*************************************************************************
	> File Name: P1055.cpp
	> Author:gpx 
	> Mail:1457495424@qq.com 
	> Created Time: 2018年08月18日 星期六 16时09分34秒
 ************************************************************************/

#include <stdio.h>

int main() {
    char num[15], x = 'z';
    int ans = 0;
    for (int i = 1; i <= 13; i++) {
        scanf("%c", &num[i]);
    }
    for (int i = 1, j = 1; i <= 11; i++) {
        if (i == 2 || i == 6) continue;
        ans += (num[i] - '0') * j;
        j++;
    }
    ans %= 11;
    if (ans == 10) {
        x = 'X';
        if (x == num[13]) {
            printf("Right\n");
        } else {
            for (int i = 1; i <= 12; i++) {
                printf("%c", num[i]);
            }
            printf("%c\n", x);
        }
    } else {
        if (ans == (num[13] - '0')) {
            printf("Right\n");
        } else {
            for (int i = 1; i <= 12; i++) {
                printf("%c", num[i]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
