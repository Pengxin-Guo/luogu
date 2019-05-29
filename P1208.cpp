/*************************************************************************
	> File Name: P1208.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月29日 星期三 20时48分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 2000000

int n, m;

struct Node {
    int p, a;
} node[MAX_N + 5];

int cmp(Node n1, Node n2) {
    return n1.p < n2.p;
}

int main() {
    long long sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> node[i].p >> node[i].a;
    }
    sort(node, node + m, cmp);
    for (int i = 0; i < m && n > 0; i++) {
        if (n > node[i].a) {
            sum += node[i].p * node[i].a;
            n -= node[i].a;
        } else {
            sum += n * node[i].p;
            n = 0;
        }
    }
    cout << sum << endl;
    return 0;
}
