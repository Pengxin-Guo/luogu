/*************************************************************************
	> File Name: P1423.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月26日 星期四 11时55分08秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int ans = 0;
    double x, distance = 0, temp = 2;
    scanf("%lf",&x);
    while (distance < x) {
        distance += temp;
        temp *= 0.98;
        ans +=1;
    }
    printf("%d\n",ans);
    return 0;
}
