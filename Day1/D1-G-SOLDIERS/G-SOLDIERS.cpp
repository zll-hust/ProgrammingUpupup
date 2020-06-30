#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int *x = new int[n + 5];
    int *y = new int[n + 5];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    sort(x, x + n);
    sort(y, y + n);
    for (int i = 0; i < n; i++)
        x[i] -= i;
    sort(x, x + n);

    int move = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--)
        move += y[j] - y[i] + x[j] - x[i];

    printf("%d", move);
    return 0;
}