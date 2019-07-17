/*************************************************************************
	> File Name: P1908.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年07月17日 星期三 20时55分13秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX_N 500000

int n;
int arr[MAX_N + 5];
long long ans = 0;


void merge_sort(int *num, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
            ans += (mid - p1 + 1);     // 用于统计逆序对
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    merge_sort(arr, 0, n - 1);
    printf("%lld\n", ans);
    return 0;
}
