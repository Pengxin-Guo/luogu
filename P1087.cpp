/*************************************************************************
	> File Name: P1087.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月01日 星期四 19时11分20秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_N 1024

typedef struct Node {
    string s;
    char c;
    struct Node *lchild, *rchild;
} Node;
int n;
string str;

char change(string str) {
    int temp1 = 0, temp2 = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '0') temp1 = 1;
        else if (str[i] == '1') temp2 = 1;
    }
    if (temp1 == 1 && temp2 == 1) {
        return 'F';
    } else if (temp1 == 1) {
        return 'B';
    } else if (temp2 == 1) {
        return 'I';
    }
}

Node *build_tree(string str) {
    Node *temp = (Node *)calloc(sizeof(Node), 1);
    temp->s = str;
    temp->c = change(str);
    int len = str.length();
    if (len == 1) return temp;
    temp->lchild = build_tree(str.substr(0, len >> 1));
    temp->rchild = build_tree(str.substr(len >> 1, len));
    return temp;
}

// 后序遍历
void output(Node *head) {
    if (head == NULL) return ;
    if (head->lchild) output(head->lchild);
    if (head->rchild) output(head->rchild);
    cout << head->c;
    return ;
}

int main() {
    cin >> n;
    cin >> str;
    Node *head = (Node *)calloc(sizeof(Node), 1);
    head = build_tree(str);
    output(head);
    cout << endl;
    return 0;
}
