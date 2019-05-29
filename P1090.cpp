/*************************************************************************
	> File Name: P1090.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月28日 星期二 21时04分58秒
 ************************************************************************/
// 建立一棵哈弗曼树, 将非叶子节点的所有权值相加即可

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000
typedef long long LL;

int n;
LL arr[MAX_N + 5];
LL sum = 0;

void haffman(LL *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[n - i - 1]) {
                swap(arr[j], arr[n - i - 1]);       // arr[n - i - 1]存放最小的那个值
            }
            if (arr[j] < arr[n - i - 2]) {
                swap(arr[j], arr[n - i - 2]);       // arr[n - i - 2]存放次小的那个值
            }
        }
        LL temp = arr[n - i - 1] + arr[n - i - 2];
        arr[n - i - 2] = temp;
        sum += temp;
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    haffman(arr, n);
    cout << sum << endl;
    return 0;
}
