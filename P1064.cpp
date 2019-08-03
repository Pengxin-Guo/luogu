/*************************************************************************
	> File Name: P1064.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月03日 星期六 10时30分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 32000
#define MAX_M 60

int v[MAX_M + 5][3], p[MAX_M + 5][3];
// v[i][j]代表第i个主件的第j个附件的价钱;p[i][j]代表第i个主件的第j个附件的等级
// 只能索引到主件,附件通过第二维索引
int f[MAX_N + 5];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int vv, pp, qq;
        cin >> vv >> pp >> qq;
        if (qq == 0) {             // 是主件
            v[i][0] = vv;
            p[i][0] = pp;
        } else {
            if (v[qq][1] == 0) {   // 是第一个附件
                v[qq][1] = vv;
                p[qq][1] = pp;
            } else {               // 是第二个附件 
                v[qq][2] = vv;
                p[qq][2] = pp;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 0; j--) {
            if (j >= v[i][0]) f[j] = max(f[j], f[j - v[i][0]] + v[i][0] * p[i][0]);
            if (j >= v[i][0] + v[i][1]) f[j] = max(f[j], f[j - v[i][0] - v[i][1]] + v[i][0] * p[i][0] + v[i][1] * p[i][1]);
            if (j >= v[i][0] + v[i][2]) f[j] = max(f[j], f[j - v[i][0] - v[i][2]] + v[i][0] * p[i][0] + v[i][2] * p[i][2]);
            if (j >= v[i][0] + v[i][1] + v[i][2]) f[j] = max(f[j], f[j - v[i][0] - v[i][1] - v[i][2]] + v[i][0] * p[i][0] + v[i][1] * p[i][1] + v[i][2] * p[i][2]);
        }
    }
    cout << f[n] << endl;
    return 0;
}
