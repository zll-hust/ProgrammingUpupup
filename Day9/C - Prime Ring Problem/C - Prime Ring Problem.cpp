#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

int n;
int vis[25];
int order[25];

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if ((n % i) == 0)
            return false;
    }
    return true;
}

void dfs(int m)
{
    // for (int i = 1; i <= m - 1; i++)
    //     printf("%d ", order[i]);
    // cout << endl;
    if ((n + 1) == m && isPrime(order[1] + order[n]))
    {
        for (int i = 1; i <= n; i++)
            printf("%d ", order[i]);
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            order[m] = i;
            if (m == 1 || isPrime(order[m - 1] + order[m]))
                dfs(m + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase = 0;
    while (cin >> n)
    {
        if(kase)
            cout << endl;
        printf("Case %d:\n", ++kase);
        memset(vis, 0, sizeof(vis));
        memset(order, 0, sizeof(order));
        order[1] = 1;
        vis[1] = 1;
        dfs(2);
    }
    return 0;
}