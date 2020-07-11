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

//输入一个子天平，返回子天平是否平衡，参数W修改为子天平的总重量
bool solve(int &W)
{
    int W1, D1, W2, D2;
    bool b1 = true, b2 = true;
    cin >> W1 >> D1 >> W2 >> D2;
    if (!W1)
        b1 = solve(W1);
    if (!W2)
        b2 = solve(W2);
    W = W1 + W2;
    return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase, W;
    cin >> kase;
    while (kase--)
    {
        if (solve(W))
            cout << "YES\n";
        else
            cout << "NO\n";
        if (kase)
            cout << "\n";
    }
    return 0;
}