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

const int maxn = 100 + 5;
char pic[maxn][maxn];
int m, n;
int idx[maxn][maxn]; //idx标记是否访问过

void dfs(int r, int c, int id)
{
    if (r < 0 || r >= m || c < 0 || c >= n)
        return; //"出界"的格子
    if (idx[r][c] > 0 || pic[r][c] != '@')
        return;     //不是"@"或者已经访问过的格子
    idx[r][c] = id; //连通分量编号 (其实标记为1就够了)
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (dr != 0 || dc != 0)
                dfs(r + dr, c + dc, id);
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (scanf("%d%d", &m, &n) == 2 && m && n)
    {
        for (int i = 0; i < m; i++)
            scanf("%s", pic[i]);
        memset(idx, 0, sizeof(idx));
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (idx[i][j] == 0 && pic[i][j] == '@')
                    dfs(i, j, ++cnt);
        printf("%d\n", cnt);
    }
    return 0;
}
