#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

// #define LOCAL
#define E 0
#define N 1
#define W 2
#define S 3

struct Robot
{
    int x;
    int y;

    Robot()
    {
        this->x = -1;
        this->y = -1;
    }
};

int graph[55][55];

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    Robot r0;
    // 初始化地图
    for (int j = 1; j <= m; j++)
        graph[0][j] = -1; // -1代表墙体
    for (int i = 1; i <= n; i++)
    {
        graph[i][0] = -1; // -1代表墙体
        for (int j = 1; j <= m; j++)
            graph[i][j] = 0; // 0代表空地
        graph[i][m + 1] = -1;
    }
    for (int j = 1; j <= m; j++)
        graph[n + 1][j] = -1; // -1代表墙体

    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            if (str[j - 1] == '#')
                graph[i][j] = -1; // -1代表墙体
            else if (str[j - 1] == 'S')
            {
                // graph[i][j] = 2; // 2代表入口 可以回到入口！！
                r0.y = i;
                r0.x = j;
            }
            else if (str[j - 1] == 'E')
                graph[i][j] = 3; // 3代表出口
        }
    }

    string path;
    cin >> path;
    int d[4];
    int ans = 0;
    int i = 0, j, k;

    for (int i = 0; i < 4; i++)
    {
        d[i] = 0;
        for (int j = 0; j < 4; j++)
        {
            if (j == i)
                continue;
            d[j] = 1;
            for (int k = 0; k < 4; k++)
            {
                if (k == i || k == j)
                    continue;
                d[k] = 2;
                for (int o = 0; o < 4; o++)
                {
                    if (o == i || o == j || o == k)
                        continue;
                    d[o] = 3;

                    Robot r = r0;
                    for (int l = 0; l < path.length(); l++)
                    {
                        int step = path[l] - '0';
                        if (d[step] == E)
                            r.x++;
                        else if (d[step] == N)
                            r.y++;
                        else if (d[step] == W)
                            r.x--;
                        else
                            r.y--;
                        if (graph[r.y][r.x])
                            break;
                    }
                    if (graph[r.y][r.x] == 3)
                        ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}