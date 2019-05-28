/*************************************************************************
	> File Name: P1781.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月28日 星期二 20时37分36秒
 ************************************************************************/
// 第二遍才过
// 用sort的时候注意起止位置！！！

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

struct Per {
    int id;
    string vote;
    int len;
} per[MAX_N + 5];
int n;

void init() {
    for (int i = 1; i <= MAX_N; i++) {
        per[i].id = i;
    }
    return ;
}

int cmp(Per p1, Per p2) {
    return p1.len >= p2.len;
}

int main() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> per[i].vote;
        per[i].len = per[i].vote.length();
    }
    sort(per + 1, per + n + 1, cmp);
    int id = per[1].id;
    string vote = per[1].vote;
    int cnt = 1;
    while (cnt != n && per[cnt].len == per[cnt + 1].len) {
        if (vote < per[cnt + 1].vote) {
            vote = per[cnt + 1].vote;
            id = per[cnt + 1].id;
        }
        cnt++;
    }
    cout << id << endl;
    cout << vote << endl;
    return 0;
}
