/*************************************************************************
    > File Name: P1092.cpp
    > Author: gpx
    > Mail: 1457495424@qq.com
    > Created Time: 2019年06月12日 星期三 20时53分46秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

char a[30], b[30], c[30];
// u数组代表有没有标记这个字母, used数组代表有没有用这个数字
// p数组用来记录出现字母的顺序和字母的对应次序
// t数字代表字母和数字的对应, 即解码
int t[300], used[30], p[30], u[30], cnt;
int n;

void judge() {
    int carry = 0;
    for (int i = n; i > 0; i--) {
        int s = t[int(a[i])] + t[int(b[i])] + carry;
        if (t[int(c[i])] != s % n) return ;
        carry = s / n;
    }
    cout << t[int('A')];
    for (int i = 'A' + 1; i <= 'A' + n - 1; i++) {
        cout << " " << t[i];
    }
    cout << endl;
    exit(0);
}

int ok() {
    for (int i = n; i > 0; i--) {
        if (t[int(a[i])] == -1 || t[int(b[i])] == -1 || t[int(c[i])] == -1) continue;
        if ((t[int(a[i])] + t[int(b[i])]) % n != t[int(c[i])] && (t[int(a[i])] + t[int(b[i])] + 1) % n != t[int(c[i])]) return 0;
    }
    return 1;
}

void dfs(int now) {
    if (now > n) {
        judge();
        return ;
    }
    // 从低位向高位判断
    for (int i = n - 1; i >= 0; i--) {
        if (used[i]) continue;
        t[p[now] + 'A' - 1] = i;
        if (ok()) {
            used[i] = 1;
            dfs(now + 1);
            used[i] = 0;
        }
    }
    t[p[now] + 'A' - 1] = -1;
    return ;
}

int main() {
    memset(t, -1, sizeof(t));
    cin >> n;
    cin >> a + 1 >> b + 1 >> c + 1;
    for (int i = n; i > 0; i--) {
        if (!u[a[i] - 'A' + 1]) p[++cnt] = a[i] - 'A' + 1, u[a[i] - 'A' + 1] = 1;
        if (!u[b[i] - 'A' + 1]) p[++cnt] = b[i] - 'A' + 1, u[b[i] - 'A' + 1] = 1;
        if (!u[c[i] - 'A' + 1]) p[++cnt] = c[i] - 'A' + 1, u[c[i] - 'A' + 1] = 1;
    }
    dfs(1);
    return 0;
}
