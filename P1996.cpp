/*************************************************************************
	> File Name: P1996.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月28日 星期日 15时51分03秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    queue<int> q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) q.push(i);
    int cnt = 1;
    while (!q.empty()) {
        int curent = q.front();
        q.pop();
        if (cnt == m) {
            cout << curent << " ";
            cnt = 1;
        } else {
            cnt++;
            q.push(curent);
        }
    }
    cout << endl;
    return 0;
}
