/*************************************************************************
	> File Name: P3374.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月24日 星期五 21时36分41秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 500000

int n, m, c[MAX_N + 5];

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        c[i] += v;
    }
    return ;
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        update(i, v);
    }
    for (int i = 0; i < m; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            update(l, r);
        } else if (op == 2) {
            cout << getsum(r) - getsum(l - 1) << endl;
        }
    }
    return 0;
}
