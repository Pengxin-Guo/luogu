/*************************************************************************
	> File Name: P1328.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月27日 星期一 20时01分02秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_NA 200
#define MAX_NB 200

int arra[MAX_NA + 5];  // 小A出拳的规律
int arrb[MAX_NB + 5];  // 小B出拳的规律

int n, na, nb;

int main() {
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++) {
        cin >> arra[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> arrb[i];
    }
    int suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        int a = arra[i % na], b = arrb[i % nb];
        switch (a) {
            case 0 : {
                if (b == 2 || b == 3) suma += 1;
                else if (b == 1 || b == 4) sumb += 1;
            } break;
            case 1 : {
                if (b == 0 || b == 3) suma += 1;
                else if (b == 2 || b == 4) sumb += 1;
            } break;
            case 2 : {
                if (b == 1 || b == 4) suma += 1;
                else if (b == 0 || b == 3) sumb += 1;
            } break;
            case 3 : {
                if (b == 2 || b == 4) suma += 1;
                else if (b == 0 || b == 1) sumb += 1;
            } break;
            case 4 : {
                if (b == 0 || b == 1) suma += 1;
                else if (b == 2 || b == 3) sumb += 1;
            } break;
        }
    }
    cout << suma << " " << sumb << endl;
    return 0;
}
