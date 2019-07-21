/*************************************************************************
	> File Name: P1192.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月21日 星期日 20时24分31秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
#define MAX_K 100
#define MOD 100003

int n, k;
int d[MAX_N + 5];

int main() {
    cin >> n >> k;
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k && j < i; j++) {
            d[i] += d[i - j];
            d[i] %= MOD;
        }
        if (i <= k) d[i] += 1;
        d[i] %= MOD;
    }
    cout << d[n] << endl;
    return 0;
}
