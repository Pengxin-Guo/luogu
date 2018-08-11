/*************************************************************************
	> File Name: P1047.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 09时05分48秒
 ************************************************************************/

#include <stdio.h>
#define MAX_L 10000
#define MAX_M 100

int num[MAX_M + 5][2] = {0};
int flag[MAX_L + 5] = {0};

int main() {
    int l, m;
    scanf("%d %d", &l, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", num[i], num[i] + 1);
    }
    for (int i = 0; i < m; i++) {
        for (int j = num[i][0]; j <= num[i][1]; j++) {
            flag[j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= l; i++) {
        if (flag[i]) continue;
        ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
