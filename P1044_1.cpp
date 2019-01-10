/*************************************************************************
	> File Name: P1044_1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月10日 星期四 09时59分36秒
 ************************************************************************/
// 递推方程

#include <iostream>
using namespace std;
#define MAX_N 18

int f[MAX_N + 5] = {0};                      // f[i]表示i个数的全部可能性

int main() {
    int n;
    cin >> n;
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            f[i] += f[j] * f[i - j - 1];
        }
    }
    cout << f[n] << endl;
    return 0;
}
