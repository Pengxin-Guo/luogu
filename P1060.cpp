/*************************************************************************
	> File Name: P1060.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月03日 星期六 10时08分14秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 30000
#define MAX_M 25

int n, m;
int dp[MAX_N + 5];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, p;
        cin >> v >> p;
        for (int j = n; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + v * p);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
