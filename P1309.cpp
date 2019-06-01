/*************************************************************************
	> File Name: P1309.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月01日 星期六 20时51分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100000

struct Per {
    int id, s, w;
} per[2 * MAX_N + 5];
int n, r, q;

int cmp(Per p1, Per p2) {
    if (p1.s == p2.s) return p1.id < p2.id;
    return p1.s > p2.s;
}

void fight() {
    for (int i = 0; i < n; i += 2) {
        if (per[i].w > per[i + 1].w) per[i].s += 1;
        else per[i + 1].s += 1;
    }
    return ;
}

int main() {
    cin >> n >> r >> q;
    n <<= 1;
    for (int i = 0; i < n; i++) {
        per[i].id = i + 1;
        //cin >> per[i].s;
        scanf("%d", &per[i].s);
    }
    for (int i = 0; i < n; i++) {
        //cin >> per[i].w;
        scanf("%d", &per[i].w);
    }
    sort(per, per + n, cmp);
    while (r--) {
        fight();
        sort(per, per + n, cmp);
    }
    cout << per[q - 1].id << endl;
    return 0;
}
