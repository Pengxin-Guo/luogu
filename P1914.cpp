/*************************************************************************
	> File Name: P1914.cpp
	> Author: gpx 
	> Mail: 1457495424@qq.com 
	> Created Time: 2018年09月05日 星期三 20时56分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

char password[MAX + 5] = {0};

int main() {
    int n;
    scanf("%d%s", &n, password);
    for (int j = 0; password[j] != '\0'; j++) {
        password[j] = (password[j] - 'a' + n) % 26 + 'a';
    }
    for (int j = 0; password[j] != '\0'; j++) {
        printf("%c", password[j]);
    }
    printf("\n");
    return 0;
}
