/*************************************************************************
	> File Name: P1085.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月23日 星期一 20时03分52秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int a=7;
    for (int i = 1; i <= 7; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x + y > 8) {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
