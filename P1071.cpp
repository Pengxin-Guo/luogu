/*************************************************************************
	> File Name: P1071.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月30日 星期四 19时36分57秒
 ************************************************************************/
// 第二遍才过
// 要注意密文与原文的双向映射问题

#include <iostream>
using namespace std;

char str[30];    // 密文对应原文
char str2[30];    // 原文对应密文

int main() {
    string s1, s2, s3;     // s1密文, s2原文
    cin >> s1 >> s2 >> s3;
    if (s1.length() != s2.length()) {
        cout << "Failed" << endl;
        return 0;
    }
    for (int i = 0; i < s1.length(); i++) {
        if (str[s1[i] - 'A' + 1] != 0 && str[s1[i] - 'A' + 1] != s2[i]) {
            cout << "Failed" << endl;
            return 0;
        }
        if (str2[s2[i] - 'A' + 1] != 0 && str2[s2[i] - 'A' + 1] != s1[i]) {
            cout << "Failed" << endl;
            return 0;
        }
        str[s1[i] - 'A' + 1] = s2[i];
        str2[s2[i] - 'A' + 1] = s1[i];
    }
    for (int i = 1; i <= 26; i++) {
        if (str[i] == 0) {
            cout << "Failed" << endl;
            return 0;
        }
    }
    for (int i = 0; i < s3.length(); i++) {
        cout << str[s3[i] - 'A' + 1];
    }
    cout << endl;
    return 0;
}
