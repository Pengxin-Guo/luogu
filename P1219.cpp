/*************************************************************************
	> File Name: P1219.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月11日 星期二 19时49分07秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 13

int arr[MAX_N + 5];
int n, cnt = 0;

int b[MAX_N + 5], c[100], d[100];
//b数组表示的是列；
//c表示的是左下到右上的对角线；
//d表示的是左上到右下的对角线；

// 第x行第y列能否放棋子
// 用这种判断方法会TLE
int is_valid(int x, int y) {
    for (int i = 1; i < x; i++) {
        if (arr[i] == y || abs(y - arr[i]) == abs(x - i)) return 0;
    }
    return 1;
}

void dfs(int x) {
    if (x > n) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 1; i <= n; i++) {
                i == 1 || cout << " ";
                cout << arr[i];
            }
            cout << endl;
        }
        return ;
    }
    for (int j = 1; j <= n; j++) {
        /* 用这种方法会TLE
        if (is_valid(x, j)) {
            arr[x] = j;
            dfs(x + 1);
            arr[x] = 0;
        }
        */
        // 由于计算是否冲突比较费时,所以我们采取记录方法,直接查表判断是否冲突即可
        if (!b[j] && !c[x + j] && !d[x - j + n]) {
            arr[x] = j;
            b[j] = 1;
            c[x + j] = 1;
            d[x - j + n] = 1;
            dfs(x + 1);
            b[j] = 0;
            c[x + j] = 0;
            d[x - j + n] = 0;
        }
    }
    return ;
}

int main() {
    cin >> n;
    dfs(1);
    cout << cnt << endl;
    return 0;
}
