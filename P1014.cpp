/*************************************************************************
	> File Name: P1014.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年09月27日 星期四 16时12分07秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int data[MAX + 5] = {0};

void init() {
    for (int i = 0; i < MAX; i++) {
        data[i] = i * (i + 1) / 2;
    }
    return ;
}

int search(int x) {
    for (int i = 1; i <MAX; i++) {
        if (data[i] >= x) return i;
    }
    return -1;
}

int main() {
    init();
    int n, index;
    scanf("%d", &n);
    index = search(n);
    n -= data[index - 1];
    if (index & 1) {
        printf("%d/%d\n", index + 1 - n, n);
    } else {
        printf("%d/%d\n", n, index + 1 - n);
    }
    return 0;
}
