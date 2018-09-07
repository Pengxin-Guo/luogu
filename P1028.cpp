/*************************************************************************
	> File Name: P1028.cpp
	> Author: gpx 
	> Mail: 1457495424@qq.com 
	> Created Time: 2018年09月07日 星期五 09时41分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int data[MAX + 5] = {0};

void init() {
    for (int i = 1; i <= MAX; i++) {
        for (int j = 0; j <= i/2; j++) {
            data[i] += data[j];
        }
        data[i] += 1;
    }
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    printf("%d\n", data[n]);
    return 0;
}
