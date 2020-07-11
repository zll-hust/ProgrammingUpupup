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

int t, n;
int c[105]; //访问状态
int topo[105];
int graph[105][105]; //记录有向边

bool dfs(int u)
{
    c[u] = -1; //正在访问
    for (int v = 0; v < n; v++)
        if (graph[u][v])
        {
            if (c[v] < 0)
                return false; //存在有向环，失败退出
            else if (!c[v] && !dfs(v))
                return false;
        }
    c[u] = 1;
    topo[--t] = u; //放到首部
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int pre, nex;
        cin >> pre >> nex;
        graph[pre - 1][nex - 1] = 1;
    }

    t = n;
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
        if (!c[i])
            if (!dfs(i))
                cout << "impossible" << endl;

    for(int i = 0; i < n; i++)
        printf("%d ", topo[i] + 1);
    cout << endl;
    return 0;
}