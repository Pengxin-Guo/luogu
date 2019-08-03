/*************************************************************************
	> File Name: P1049.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月03日 星期六 16时53分11秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_V 20000

int v, n;
int dp[MAX_V + 5];

int main() {
    cin >> v >> n;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        for (int j = v; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + w);
        }
    }
    cout << v - dp[v] << endl;
    return 0;
}
