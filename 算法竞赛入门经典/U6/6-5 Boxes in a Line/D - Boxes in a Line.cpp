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

int rt[100005];
int lt[100005];
void link(int L, int R) // 连接l、r点, 注意左右顺序.注意没有修改原本的连接
{
    rt[L] = R;
    lt[R] = L;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n, m, kase = 0;
    while (cin >> n >> m)
    {
        for (int i = 1; i < n; i++)
        {
            lt[i] = i - 1;
            rt[i] = i + 1;
        }
        lt[0] = n;
        rt[0] = 1;
        lt[n] = n - 1;
        rt[n] = 0;

        int op, inv = 0, x, y;
        while (m--)
        {
            cin >> op >> x >> y;
            // 相邻时特殊处理
            if (op == 3 && rt[y] == x)
                swap(x, y);
            if (op != 3 && inv)
                op = 3 - op;
            if (op == 1 && x == lt[y])
                continue;
            if (op == 2 && x == rt[y])
                continue;

            int lx = lt[x], rx = rt[x], ly = lt[y], ry = rt[y];
            if (op == 1)
            {
                link(lx, rx);
                link(ly, x);
                link(x, y);
            }
            else if (op == 2)
            {
                link(lx, rx);
                link(y, x);
                link(x, ry);
            }
            else if (op == 3)
            {
                if (rt[x] == y)
                {
                    link(lx, y);
                    link(y, x);
                    link(x, ry);
                }
                else
                {
                    link(lx, y);
                    link(y, rx);
                    link(ly, x);
                    link(x, ry);
                }
            }
        }

        int nex = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            nex = rt[nex];
            if (i % 2 == 1)
                ans += nex;
        }
        // 偶数个时反转，所求即为偶数下标和
        if (inv && n % 2 == 0)
            ans = (ll)(n * (n + 1) / 2) - ans;
        printf("Case %d: %lld\n", ++kase, ans);
    }
}