/*************************************************************************
	> File Name: P1305_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月02日 星期五 17时08分20秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 26

char a[MAX_N + 5][3];
int n;

void dfs(char x) {
    if (x == '*') return ;
    cout << x;
    for (int i = 1; i <= n; i++) {
        if (a[i][0] == x) {
            dfs(a[i][1]);
            dfs(a[i][2]);
        }
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    dfs(a[1][0]);
    cout << endl;
    return 0;
}
