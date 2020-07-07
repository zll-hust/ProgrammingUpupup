#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
using namespace std;

typedef long long LL;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
//#define LOCAL

int x[200005];
int y[200005];

void swap(int& x, int& y)
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
    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (!temp)
            continue;
        else
            x[m++] = temp;
    }
    m = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (!temp)
            continue;
        else
            y[m++] = temp;
    }

    bool flag = true;
    int k = 0;
    while (x[k] != y[0])
    {
        k++;
    }
    n--;
    for (int j = 0; j < n; j++)
    {
        if (x[(k++) % n] != y[j]) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}