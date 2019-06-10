/*************************************************************************
	> File Name: P1309.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月01日 星期六 20时51分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
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

// 每一次两两比较，赢的放在一个数组，输的放在另一个数组
void fight() {
    Per *temp1 = (Per *)malloc(sizeof(Per) * n);     // 赢
    Per *temp2 = (Per *)malloc(sizeof(Per) * n);     // 输
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i += 2) {
        if (per[i].w > per[i + 1].w) {
            per[i].s += 1;
            temp1[cnt1++] = per[i];
            temp2[cnt2++] = per[i + 1];
        }
        else {
            per[i + 1].s += 1;
            temp1[cnt1++] = per[i + 1];
            temp2[cnt2++] = per[i];
        }
    }
    int k = 0, p1 = 0, p2 = 0;
    while (p1 < cnt1 || p2 < cnt2) {
        if (p1 < cnt1 && p2 < cnt2 && temp1[p1].s == temp2[p2].s) {
            if (temp1[p1].id < temp2[p2].id) {
                per[k++] = temp1[p1++];
            } else {
                per[k++] = temp2[p2++];
            }
        } else if (p2 >= cnt2 || (p1 < cnt1 && temp1[p1].s > temp2[p2].s)) {
            per[k++] = temp1[p1++];
        } else {
            per[k++] = temp2[p2++];
        }
    }
    free(temp1);
    free(temp2);
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
    }
    cout << per[q - 1].id << endl;
    return 0;
}
