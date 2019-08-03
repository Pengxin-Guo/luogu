/*************************************************************************
	> File Name: P1616.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月03日 星期六 16时58分45秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_T 100000
#define MAX_M 10000

int t, m;
int dp[MAX_T + 5];

int main() {
    cin >> t >> m;
    for (int i = 0; i < m; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = w; j <= t; j++) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[t] << endl;
    return 0;
}
