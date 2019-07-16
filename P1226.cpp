/*************************************************************************
	> File Name: P1226.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月16日 星期二 21时26分41秒
 ************************************************************************/

#include <iostream>
using namespace std;
typedef long long LL;

LL b, p, k;

// 返回x^y mod k
LL func(LL x, LL y) {
    if (y == 0) return 1 % k;
    LL ret = 1;
    while (y) {
        if (y & 1) {
            ret = (ret * x) % k;
        }
        y >>= 1;
        x = (x * x) % k;
    }
    return ret;
}

int main() {
    cin >> b >> p >> k;
    LL ans = func(b, p);
    cout << b << "^" << p << " mod " << k << "=" << ans << endl;
    return 0;
}
