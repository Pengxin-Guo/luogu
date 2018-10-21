/*************************************************************************
	> File Name: P1981.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月21日 星期日 16时13分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1300000
#define MOD_NUM 10000

int calc(char *str) {
    int len = strlen(str);
    for (int i = 0; str[i]; i++) str[i] = (str[i] == '+' ? 0 : str[i]);
    int total = 0;
    for (int j = 0; j < len; j += strlen(str + j) + 1) {
        int num = 0, p = 1;
        for (int i = j; str[i]; i++) {
            switch (str[i]) {
                case '*' : p *= num; p %= MOD_NUM; num = 0; break;
                default : num = num * 10 + str[i] - '0';
            }
        }
        p *= num;
        p %= MOD_NUM;
        total += p;
        total %= MOD_NUM;
    }
    return total;
}

int main() {
    char str[MAX];
    scanf("%s", str);
    printf("%d\n", calc(str));
    return 0;
}
