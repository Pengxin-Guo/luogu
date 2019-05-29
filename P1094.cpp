/*************************************************************************
	> File Name: P1094.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月29日 星期三 21时04分50秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 30000

int a[MAX_N + 5];
int n, w;

int main() {
    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int cnt = 0, l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] <= w) {
            l++;
            r--;
        } else {
            r--;
        }
        cnt += 1;
    }
    cnt += (l == r);
    cout << cnt << endl;
    return 0;
}
