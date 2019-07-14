/*************************************************************************
	> File Name: P1118.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月14日 星期日 18时21分22秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, sum;
int a[15];
int log_a[15][15];

int cmp(int x, int y) {
    return x > y;
}

void init() {
    for (int i = 1; i <= n; i++) a[i] = i;
    // 找规律发现最后求和的时候, 每一项的系数是符合杨辉三角的规律的
    // 故先构造一个杨辉三角出来
    for (int i = 1; i <= n; i++) log_a[i][1] = log_a[i][i] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= (i - 1) / 2; j++) {
            log_a[i][j + 1] = log_a[i][i - j] = log_a[i - 1][j] + log_a[i - 1][j + 1];
        }
    }
    return ;
}

int is_valid(int *arr) {
    int temp = 0;
    for (int i = 1; i <= n; i++) {
        temp += a[i] * log_a[n][i];
        if (temp > sum) {
            // 剪枝部分
            // 如果从这儿开始数字之和大于最终答案, 那么之后所有的全排列边都不再符合条件
            sort(a + i, a + n + 1, cmp);
            return 0;
        }
    }
    return temp == sum;
}

void output(int *arr) {
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
} 

int main() {
    cin >> n >> sum;
    init();
    do {
        if (is_valid(a)) {
            output(a);
            break;
        }
    } while (next_permutation(a + 1, a + 1 + n));
    return 0;
}
