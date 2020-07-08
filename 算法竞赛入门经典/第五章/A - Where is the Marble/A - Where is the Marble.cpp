#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int marbles[10005];

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n, m, kase;
    kase = 1;
    while (cin >> n >> m && n && m) {
        printf("CASE# %d:\n", kase++);
        for (int i = 0; i < n; i++)
            cin >> marbles[i];
        sort(marbles, marbles + n);
        for (int i = 0; i < m; i++) {
            int mar;
            cin >> mar;
            int pos = lower_bound(marbles, marbles + n, mar) - marbles; // lowerbound返回的是指针,获得位置需要减去数组的初始位置
            if (marbles[pos] == mar)
                printf("%d found at %d\n", mar, pos + 1);
            else
                printf("%d not found\n", mar);
        }
    }

    return 0;
}