/*************************************************************************
	> File Name: P1464.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月26日 星期三 16时42分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int ans[21][21][21] = {0};

int w(int64_t a, int64_t b, int64_t c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    else if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    else if (a < b && b < c) {
        if (ans[a][b][c]) return ans[a][b][c];
        ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return ans[a][b][c];
    }
    else {
        if (ans[a][b][c]) return ans[a][b][c];
        ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return ans[a][b][c];
    }   
}

int main() {
    int64_t a, b, c;
    int ans;
    while(scanf("%" PRId64 "%" PRId64 "%" PRId64, &a, &b, &c) != EOF) {
        if (a == -1 && b == -1 && c == -1) break;
        ans = w(a, b, c);
        printf("w(%" PRId64 ", %" PRId64 ", %" PRId64 ") = %d\n", a, b, c, ans);
    }
    //printf("%" PRId64 "\n", a);
    return 0;
}
