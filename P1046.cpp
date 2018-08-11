/*************************************************************************
	> File Name: P1046.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 08时57分20秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int num[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (num[i] <= (n + 30)) {
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
