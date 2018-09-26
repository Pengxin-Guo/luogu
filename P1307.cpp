/*************************************************************************
	> File Name: P1307.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月26日 星期三 16时18分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x = 0, digit = 0;
    scanf("%d", &n);
    if (n < 0) {
        printf("-");
        n = -n;
    }
    while (n)  {
        x = x * 10 + n % 10;
        n /= 10;
    }
    printf("%d\n", x);
    return 0;
}
