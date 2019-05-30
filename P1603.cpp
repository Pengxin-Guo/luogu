/*************************************************************************
	> File Name: P1603.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月30日 星期四 20时54分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

string nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

int in(string s) {
    for (int i = 1; i <= 20; i++) {
        if (nums[i] == s) return i;
    }
    if (s == "a" || s == "first") return 1;
    else if (s == "both" || s == "another" || s == "second") return 2;
    else if (s == "third") return 3;
    return 0;
}

int main() {
    int cnt = 0, num;
    string s;
    for(int i = 0; i < 6; i++) {
        cin >> s;
        int temp = in(s);
        if (temp == 0) continue;
        cnt++;
        temp = temp * temp % 100;
        if (cnt == 1 && temp == 0) {
            cnt--;
            continue;
        }
        if (cnt == 1) cout << temp;
        else printf("%02d", temp);
    }
    if (cnt == 0) cout << 0;
    cout << endl;
    return 0;
}
