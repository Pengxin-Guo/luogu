/*************************************************************************
	> File Name: P1567.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 10时14分12秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000000

int data[MAX_N + 5] = {0};
int b[MAX_N + 5] = {0};

 int main() {
     int n, ans = 0, flag = 0, temp = 1;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
         scanf("%d", &data[i]);
     }
     for (int i = 0; i < n; i++) {
         if (data[i + 1] > data[i]) {
             temp += 1;
             continue;
         }
         b[flag] = temp;
         flag = i + 1;
         temp = 1;
     }
     for (int i = 0; i < n; i++) {
         if (ans < b[i]) ans = b[i];
     }
     printf("%d\n", ans);
     return 0;
 }
