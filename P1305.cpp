/*************************************************************************
	> File Name: P1305.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月02日 星期五 16时46分25秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_N 26

typedef struct Node {
    char l, r;
} Node;

Node arr[MAX_N + 5];
int flag[MAX_N + 5];
int n;

typedef struct Tree {
    char c;
    Tree *lchild, *rchild;
} Tree;

Tree *build_tree(int st) {
    if (flag[st] == 0) return NULL;
    Tree *temp = (Tree *)calloc(sizeof(Tree), 1);
    temp->c = st + 'a';
    if (arr[st].l != '*') temp->lchild = build_tree(arr[st].l - 'a');
    if (arr[st].r != '*') temp->rchild = build_tree(arr[st].r - 'a');
    return temp;
}

void output(Tree *head) {
    if (head == NULL) return ;
    cout << head->c;
    if (head->lchild) output(head->lchild);
    if (head->rchild) output(head->rchild);
    return ;
}

int main() {
    int st;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        (i != 0) || (st = a - 'a');
        flag[a - 'a'] = 1;
        arr[a - 'a'].l = b;
        arr[a - 'a'].r = c;
    }
    Tree *head = (Tree *)calloc(sizeof(Tree), 1);
    head = build_tree(st);
    output(head);
    cout << endl;
    return 0;
}
