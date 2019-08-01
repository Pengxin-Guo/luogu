/*************************************************************************
	> File Name: P1030.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年08月01日 星期四 19时49分16秒
 ************************************************************************/

#include <iostream>
using namespace std;

// 根据中序遍历str1和后序遍历str2求前序遍历
void func(string str1, string str2) {
    if (str1.size() > 0) {
        char c = str2[str2.size() - 1];
        cout << c;
        int k = str1.find(c);
        func(str1.substr(0, k), str2.substr(0, k));
        func(str1.substr(k + 1), str2.substr(k, str1.size() - k - 1));
    }
    return ;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    func(str1, str2);
    cout << endl;
    return 0;
}
