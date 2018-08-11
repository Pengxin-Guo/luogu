/*************************************************************************
	> File Name: P2141.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 10时15分22秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using std::sort;
#define MAX_N 10000

int data[MAX_N + 5] = {0};

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    sort(data, data + n);
    for (int i = 2; i < n; i++) {
        //int flag = 1;
        for (int j = i - 1; j > 0; j--) {
            for (int k = j - 1; k >= 0; k--) {
                if (data[i] == data[j] + data[k]) {
                    ans += 1;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
