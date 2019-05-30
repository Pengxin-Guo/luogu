/*************************************************************************
	> File Name: P1031.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月29日 星期三 21时22分49秒
 ************************************************************************/
// 看了题解

#include <iostream>
using namespace std;
#define MAX_N 100

int arr[MAX_N + 5];
int n, sum = 0, ave = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    ave = sum / n;
    for (int i = 0; i < n; i++) {
        arr[i] -= ave;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;
        arr[i + 1] += arr[i];
        cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
