/*************************************************************************
	> File Name: P1068.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月28日 星期二 20时21分27秒
 ************************************************************************/
// 第二遍才过, 以后做题一定要细心！！！

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 5000

struct Stu {
    int k, s;
} stu[MAX_N + 5];
int n, m;

int cmp(Stu s1, Stu s2) {
    if (s1.s == s2.s) return s1.k < s2.k;
    return s1.s > s2.s;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].k >> stu[i].s;
    }
    sort(stu, stu + n, cmp);
    m *= 1.5;
    m -= 1;
    int line = stu[m].s;
    while (stu[m].s == stu[m + 1].s) m++;
    cout << line << " " << m + 1 << endl;
    for (int i = 0; i <= m; i++) {
        cout << stu[i].k << " " << stu[i].s << endl;
    }
    return 0;
}
