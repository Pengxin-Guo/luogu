/*************************************************************************
	> File Name: P1044_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月10日 星期四 10时57分44秒
 ************************************************************************/
// 搜索 + 记忆化

#include <iostream>
using namespace std;

#define MAX_N 18
int f[MAX_N + 5][MAX_N + 5] = {0};

int dfs(int x, int y) {                          // x代表操作数序列中有几个数, y代表栈中有几个数
    if (f[x][y]) return f[x][y];
    if (x == 0) return 1;
    if (y > 0) f[x][y] += dfs(x, y - 1);
    f[x][y] += dfs(x - 1, y + 1);
    return f[x][y];
    
}

int main() {
    int n;
    cin >> n;
    cout << dfs(n, 0) << endl;
    return 0;
}
