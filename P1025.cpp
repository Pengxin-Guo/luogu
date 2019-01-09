/*************************************************************************
	> File Name: P1025.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月09日 星期三 17时55分26秒
 ************************************************************************/
// 递推状态确定了之后，递推方程的推导也是十分重要的
// 还是要多思考才行

#include <iostream>
using namespace std;
#define MAX_N 200
#define MAX_K 6

int main() {
    int n, k;
    int data[MAX_N + 5][MAX_K + 5] = {0};
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        data[i][1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            if (i < j) continue;
            data[i][j] = data[i - 1][j - 1] + data[i - j][j];
        }
    }
    cout << data[n][k] << endl;
    return 0;
}
