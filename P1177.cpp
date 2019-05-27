/*************************************************************************
	> File Name: P1177.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月27日 星期一 20时32分18秒
 ************************************************************************/
// 普通的快排过不去, 需要优化基准值的选取

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX_N 100000

int arr[MAX_N + 5];
int n;

void myswap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return ;
}

int random(int *a, int l, int r) {
    srand(time(0));
    int pivot = rand() % (r - l) + l;
    myswap(a[pivot], a[l]); 
    return a[l];
}

void quick_sort(int *num, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, z = random(num, l, r);
    while (x < y) {
        while (x < y && num[y] >= z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        //cin >> arr[i];
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        //i == 0 || cout << " ";
        //cout << arr[i];
        i == 0 || printf(" ");
        printf("%d", arr[i]);
    }
    //cout << endl;
    printf("\n");
    return 0;
}
