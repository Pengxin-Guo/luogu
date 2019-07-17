/*************************************************************************
	> File Name: P1010.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月17日 星期三 19时57分22秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

// 11110000
int ind(int n) {
    int l = -1, r = 15;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (pow(2, mid) <= n) l = mid;
        else r = mid - 1;
    }
    return l;
}

void func(int n) {
    int num = ind(n), left = n - pow(2, num);
    if (num == 2) {
        cout << "2(2)";
    } else if (num == 1) {
        cout << "2";
    } else if (num == 0) {
        cout << "2(0)";
    } else {
        cout << "2(";
        func(num);
        cout << ")";
    }
    if (left != 0) {
        cout << "+";
        func(left);
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    func(n);
    cout << endl;
    return 0;
}
