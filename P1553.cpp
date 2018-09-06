/*************************************************************************
	> File Name: P1553.cpp
	> Author: gpx 
	> Mail: 1457495424@qq.com 
	> Created Time: 2018年09月06日 星期四 20时49分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20 

char num[MAX + 5] = {0};

int main() {
    scanf("%s", num);
    int decimal = -1, fraction = -1, percentage = -1, length = 0, flag = 1;
    for (int i = 0; num[i] != '\0'; i++) {
        if (num[i] == '.') decimal = i;
        if (num[i] == '/') fraction = i;
        if (num[i] == '%') percentage = i;
        length += 1;
    }
    if (decimal >= 0) {
        for (int i = decimal - 1; i >= 0; i--) {
            if (flag && num[i] == '0') continue;
            flag = 0;
            printf("%c", num[i]);
        }
        printf(".");
        int j;
        for (j = decimal + 1; j < length; j++) {
            if (num[j] != '0') break;
        }
        int flag2 = 1;
        for (int i = length - 1; i >= j; i--) {
            if (flag2 && num[i] == '0') continue;
            flag2 = 0;
            printf("%c", num[i]);
        }
        if (flag2 == 1) printf("0");
    } else if (fraction >= 0) {
        for (int i = fraction - 1; i >= 0; i--) {
            if (flag && num[i] == '0') continue;
            flag = 0;
            printf("%c", num[i]);
        }
        printf("/");
        int flag2 = 1;
        for (int i = length - 1; i > fraction; i--) {
            if (flag2 && num[i] == '0') continue;
            flag2 = 0;
            printf("%c", num[i]);
        }

    } else if (percentage >= 0) {
        for (int i = length - 2; i >= 0; i--) {
            if (flag && num[i] =='0') continue;
            flag = 0;
            printf("%c", num[i]);
        } 
        printf("%");
    } else {
        if (length ==0 && num[0] == '0') {
            printf("0");
        } else {
            for (int i = length - 1; i >= 0; i--) {
                if (flag && num[i] == '0') continue;
                flag = 0;
                printf("%c", num[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
