/*************************************************************************
	> File Name: P1111.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月24日 星期五 20时21分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
#define MAX_M 100000

struct UnionSet {
    int *father;
    int *size;
    int n;
};

struct Node {
    int x, y, t;
} node[MAX_M + 5];

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)calloc(sizeof(UnionSet), 1);
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    u->n = n;
    for (int i = 0; i < n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

int find(UnionSet *u, int x) {
    if (u->father[x] != x) {
        return (u->father[x] = find(u, u->father[x]));
    }
    return x;
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) {
        fa ^= fb, fb ^= fa, fa ^= fb;
    }
    u->father[fb] = fa;
    u->size[fa] += u->size[fb];
    return 1;
}

int cmp(Node n1, Node n2) {
    return n1.t < n2.t;
}

int main() {
    int n, m;
    cin >> n >> m;
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        cin >> node[i].x >> node[i].y >> node[i].t;
    }
    sort(node, node + m, cmp);
    int flag = 1;
    for (int i = 0; i < m && flag; i++) {
        int a = node[i].x - 1, b = node[i].y - 1;
        merge(u, a, b);
        int fa = find(u, a), fb = find(u, b);
        if (u->size[fa] == n || u->size[fb] == n) {
            cout << node[i].t << endl;
            flag = 0;
        }
    }
    if (flag) cout << -1 << endl;
    return 0;
}
