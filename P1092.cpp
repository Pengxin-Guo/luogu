/*************************************************************************
	> File Name: P1092.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月12日 星期三 20时53分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 26

int ans[MAX_N + 5]; // ans[0]存放A代表的数字, ans[1]存放B代表的数字,...依次类推
string str1, str2, str3;
int n;

void init() {
    for (int i = 0; i < 26; i++) {
        ans[i] = i;
    }
    return ;
}

int *add(string str1, string str2) {
    int *ret = (int *)malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; i--) {
        ret[i] += ans[str1[i] - 'A' + str2[i] - 'A'];
        while (ret[i] >= n) {
            ret[i] -= n;
            ret[i - 1] += 1;
        }
    }
    return ret;
}

int *str_int(string str) {
    int *ret = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ret[i] = ans[str[i] - 'A'];
    }
    return ret;
}

int same(int *ans1, int *temp) {
    for (int i = 0; i < n; i++) {
        if (ans1[i] != temp[i]) return 0;
    }
    return 1;
}

void output(int *num) {
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return ;
}

int main() {
    init();
    cin >> n;
    cin >> str1 >> str2 >> str3;
    do {
        int *ans1 = str_int(str3);
        int *temp = add(str1, str2);
        if (same(ans1, temp)) break;
        cout << "ans :";
        output(ans);
        cout << "should: ";
        output(ans1);
        cout << "cal: ";
        output(temp);
        cout << endl;
    } while (next_permutation(ans, ans + n));
    for (int i = 0; i < n; i++) {
        i == 0 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
