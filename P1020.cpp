/*************************************************************************
	> File Name: P1020.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月07日 星期三 16时05分00秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000

int arr[MAX_N + 5], dp1[MAX_N + 5], dp2[MAX_N + 5];

int main() {
    int num, cnt = 0;
    while (cin >> num) {
        arr[cnt++] = num;
    }
    for (int i = 0; i < cnt; i++) {
        int temp1 = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[j] < arr[i]) continue;
            temp1 = max(temp1, dp1[j]);
        }
        dp1[i] = temp1 + 1;
        int temp2 = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[j] >= arr[i]) continue;
            temp2 = max(temp2, dp2[j]);
        }
        dp2[i] = temp2 + 1;
    }
    int ans1 = dp1[0], ans2 = dp2[0];
    for (int i = 1; i < cnt; i++) {
        ans1 = max(ans1, dp1[i]);
        ans2 = max(ans2, dp2[i]);
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
