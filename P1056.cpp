/*************************************************************************
	> File Name: P1056.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月27日 星期一 19时21分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 1000

int n, m, k, l, d;
struct Talk {
    int id, cnt;
} ;
Talk talk1[MAX_N + 5];  // 左右交谈, 列走廊
Talk talk2[MAX_N + 5];  // 前后交谈, 行走廊
vector<int> v1, v2;

void init() {
    for (int i = 1; i <= MAX_N; i++) {
        talk1[i].id = i;
        talk2[i].id = i;
    }
    return ;
}

int cmp(Talk t1, Talk t2) {
    return t1.cnt > t2.cnt;
}

int main() {
    init();
    cin >> n >> m >> k >> l >> d;
    for (int i = 1; i <= d; i++) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (x == p) {
            int minn = min(y, q);
            talk1[minn].cnt += 1;
        } else if (y == q) {
            int minn = min(x, p);
            talk2[minn].cnt += 1;
        }
    }
    sort(talk1, talk1 + m, cmp);
    sort(talk2, talk2 + n, cmp);
    for (int i = 0; i < k; i++) {
        v1.push_back(talk2[i].id);
    }
    for (int i = 0; i < l; i++) {
        v2.push_back(talk1[i].id);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
    return 0;
}
