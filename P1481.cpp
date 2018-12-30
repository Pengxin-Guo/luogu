/*************************************************************************
	> File Name: P1481.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年12月30日 星期日 20时53分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define BASE_CNT 26
#define BASE 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE_CNT];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE_CNT; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    return p;
}

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 1;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
        }
        p = p->next[str[i] - BASE];
        cnt += p->flag;
    }
    p->flag = 1;
    return cnt;
}

int main() {
    Node *root = getNewNode();
    char str[100];
    int n, ans = 0, temp;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        temp = insert(root, str);
        if (temp > ans) ans = temp;
    }
    printf("%d\n", ans);
    return 0;
}
