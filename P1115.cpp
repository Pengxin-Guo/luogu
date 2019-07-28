/*************************************************************************
	> File Name: P1115.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月28日 星期日 15时59分45秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 200000

int n, num, maxx, sum;

int main() {
    cin >> n;
    cin >> maxx;
    sum = maxx;
    for (int i = 2; i <= n; i++) {
        cin >> num;
        sum = sum > 0 ? sum : 0;
        sum += num;
        maxx = max(maxx, sum);
    }
    cout << maxx << endl;
    return 0;
}
