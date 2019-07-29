/*************************************************************************
	> File Name: P1160.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月28日 星期日 17时30分29秒
 ************************************************************************/
// 自己做的时候为什么想不到把数组和链表结合起来使用呢?
// 链表方便插入和删除, 但是定位一个节点却很慢啊
// 之前就是只知道用纯链表, 导致一直TLE
// 后面看了题解才知道竟然可以将链表的地址记录到数组里面, 这样定位节点就是0(1)了
// 还是自己太菜了

#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_N 100000

typedef struct Node {
    int num;
    Node *pre, *next;
} Node;
int n, m;
Node *ind[MAX_N + 5];  // 用来记录每个节点的地址

int main() {
    Node head;
    cin >> n;
    Node *node = (Node *)calloc(sizeof(Node), 1);
    node->num = 1;
    head.next = node;
    node->pre = &head;
    ind[1] = node;
    for (int i = 2; i <= n; i++) {
        Node *temp = (Node *)calloc(sizeof(Node), 1);
        temp->num = i;
        ind[i] = temp;
        int k, p;
        cin >> k >> p;
        Node *cur = ind[k];
        if (p == 0) {
            cur->pre->next = temp;
            temp->pre = cur->pre;
            temp->next = cur;
            cur->pre = temp;
        } else if (p == 1) {
            if (cur->next == NULL) {
                cur->next = temp;
                temp->pre = cur;
            } else {
                cur->next->pre = temp;
                temp->next = cur->next;
                temp->pre = cur;
                cur->next = temp;
            }
        }
    }
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        Node *cur = ind[x];
        if (cur == NULL) continue;
        if (cur->next == NULL) {
            cur->pre->next = NULL;
        } else {
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
        }
        ind[x] = NULL;
        free(cur);
    }
    for (Node *cur = head.next; cur; cur = cur->next) {
        cur == head.next || cout << " ";
        cout << cur->num;
    }
    cout << endl;
    return 0;
}
