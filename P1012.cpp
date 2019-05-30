/*************************************************************************
	> File Name: P1012.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月30日 星期四 20时23分01秒
 ************************************************************************/
// 第二遍才过
// 注意排序比较规则

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

string nums[MAX_N + 5];
int n;

int cmp(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length(), l = min(l1, l2);
    for (int i = 0; i < l; i++) {
        if (s1[i] == s2[i]) continue;
        else return s1[i] > s2[i];
    }
    if (l1 == l) {
        return s1[0] > s2[l];
    } else {
        return s1[l] > s2[0];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << nums[i];
    }
    cout << endl;
    return 0;
}
