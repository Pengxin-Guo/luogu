/*************************************************************************
	> File Name: P1051.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年06月01日 星期六 20时20分26秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100

struct Stu {
    string name;
    int g1, g2;
    char c1, c2;
    int cnt;
};

int func(Stu st) {
    int money = 0;
    if (st.g1 > 80 && st.cnt >= 1) money += 8000;
    if (st.g1 > 85 && st.g2 > 80) money += 4000;
    if (st.g1 > 90) money += 2000;
    if (st.g1 > 85 && st.c2 == 'Y') money += 1000;
    if (st.g2 > 80 && st.c1 == 'Y') money += 850;
    return money;
}

int main() {
    int n, sum = 0, money = 0;
    Stu ans, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp.name >> temp.g1 >> temp.g2 >> temp.c1 >> temp.c2 >> temp.cnt;
        int mm = func(temp);
        if (money < mm) {
            ans = temp;
            money = mm;
        }
        sum += mm;
    }
    cout << ans.name << endl;
    cout << money << endl;
    cout << sum << endl;
    return 0;
}
