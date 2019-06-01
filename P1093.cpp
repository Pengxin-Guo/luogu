/*************************************************************************
	> File Name: P1093.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月01日 星期六 20时42分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 300

struct Stu {
    int id, g1, g2, g3, g;
} stu[MAX_N + 5];
int n;

int cmp(Stu s1, Stu s2) {
    if (s1.g == s2.g && s1.g1 == s2.g1) {
        return s1.id < s2.id;
    } else if (s1.g == s2.g) {
        return s1.g1 > s2.g1;
    }
    return s1.g > s2.g;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        stu[i].id = i + 1;
        cin >> stu[i].g1 >> stu[i].g2 >> stu[i].g3;
        stu[i].g = stu[i].g1 + stu[i].g2 + stu[i].g3;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < 5; i++) {
        cout << stu[i].id << " " << stu[i].g << endl;
    }
    return 0;
}
