/*************************************************************************
	> File Name: P1089.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月23日 星期一 21时02分03秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int num=300;
    int ans=0;
    int money;
    for (int i = 1; i <= 12; i++) {
        scanf("%d",&money);
        if (num - money < 0) {
            printf("%d\n",-i);
            return 0;
        }
        ans = ans + (num - money) / 100 * 100;
        num = 300 + num - money - (num - money) / 100 * 100;
    }
    printf("%d\n",ans * 12 / 10 + num - 300);
    return 0;
}
