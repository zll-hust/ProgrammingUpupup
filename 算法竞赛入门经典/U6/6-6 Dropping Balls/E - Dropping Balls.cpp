#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

typedef long long ll;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
#define LOCAL

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase;
    cin >> kase;
    int D, I;
    while (scanf("%d%d", &D, &I) == 2)
    {
        int k = 1;
        for (int i = 0; i < D - 1; i++)
            if (I % 2)
            {
                k = k * 2;
                I = (I + 1) / 2;
            }
            else
            {
                k = k * 2 + 1;
                I /= 2;
            }
        printf("%d\n", k);
    }

    return 0;
}