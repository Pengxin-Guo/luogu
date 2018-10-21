/*************************************************************************
	> File Name: P1054.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月21日 星期日 15时36分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 0x3f3f3f3f

int calc(const char *str,int l, int r, int value) {
    int pos = -1, temp_prior = 0, prior = INF - 1;
    for (int i = l; i <= r; i++) {
        int cur_prior = INF;
        switch (str[i]) {
            case '(' : temp_prior += 100; break;
            case ')' : temp_prior -= 100; break;
            case '+' : cur_prior = temp_prior + 1; break;
            case '-' : cur_prior = temp_prior + 1; break;
            case '*' : cur_prior = temp_prior + 2; break;
            case '/' : cur_prior = temp_prior + 2; break;
            case '^' : cur_prior = temp_prior + 3; break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] == 'a') return value;
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    } else {
        int a = calc(str, l, pos - 1, value);
        int b = calc(str, pos + 1, r, value);
        switch (str[pos]) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
            case '^' : return (int)pow(a, b);
        }
    }
    return 0;
}

int main() {
    char str[100], temp[100], ans[30];
    scanf("%[^\n]s", str);
    //printf("%d\n", calc(str, 0, strlen(str) - 1, 3));
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%[^\n]s", temp);
        int flag = 1;
        for (int j = 1; j <= 5; j++) {
            int ran = rand() % 100;
            //printf("%d  %d\n", calc(str, 0, strlen(str) - 1, ran), calc(temp, 0, sizeof(temp) - 1, ran));
            if (calc(str, 0, strlen(str) - 1, ran) == calc(temp, 0, sizeof(temp) - 1, ran)) continue;
            flag = 0;
        }
        if (flag) {
            ans[cnt] = i + 65;
            cnt++;
        }
        memset(temp, 0, sizeof(temp));
    }
    for (int i = 0; i < cnt; i++) printf("%c", ans[i]);
    printf("\n");
    return 0;
}
