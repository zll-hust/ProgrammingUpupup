#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

#define LOCAL
#define E 0
#define N 1
#define W 2
#define S 3

int Id = 0;

struct Robot
{
    int id;
    int x;
    int y;
    int dir;

    Robot()
    {
        this->id = Id++;
        this->x = -1;
        this->y = -1;
        this->dir = -1;
    }
} robots[105];

int graph[105][105];

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int a, b;
        cin >> a >> b;
        // 初始化地图
        for (int j = 1; j <= a; j++)
            graph[0][j] = -1; // -1代表墙体
        for (int i = 1; i <= b; i++)
        {
            graph[i][0] = -1; // -1代表墙体
            for (int j = 1; j <= a; j++)
                graph[i][j] = 0; // 0代表空地
            graph[i][a + 1] = -1;
        }
        for (int j = 1; j <= a; j++)
            graph[b + 1][j] = -1; // -1代表墙体

        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            char dir;
            cin >> robots[i].x >> robots[i].y >> dir;
            if (dir == 'E')
                robots[i].dir = 0;
            else if (dir == 'N')
                robots[i].dir = 1;
            else if (dir == 'W')
                robots[i].dir = 2;
            else
                robots[i].dir = 3;
            graph[robots[i].y][robots[i].x] = robots[i].id; // 更新graph，graph上的数字表示机器编号
        }

        int r1 = -1;
        int r2 = -1;
        while (m--)
        {
            int robot;
            char behave;
            int lenth;
            cin >> robot >> behave >> lenth;
            if (behave == 'L')
                robots[robot].dir = (robots[robot].dir + lenth) % 4;
            else if (behave == 'R')
                robots[robot].dir = (robots[robot].dir - lenth) % 4;
            else
            {
                if (robots[robot].dir == E)
                {
                    graph[robots[robot].y][robots[robot].x] = 0;
                    for (int j = 1; j <= lenth; j++)
                    {
                        if (graph[robots[robot].y][robots[robot].x + j])
                        {
                            r1 = robots[robot].id;
                            r2 = graph[robots[robot].y][robots[robot].x + j];
                            goto end;
                        }
                    }
                    robots[robot].x += lenth;
                    graph[robots[robot].y][robots[robot].x] = robots[robot].id;
                }
                else if (robots[robot].dir == N)
                {
                    graph[robots[robot].y][robots[robot].x] = 0;
                    for (int j = 1; j <= lenth; j++)
                    {
                        if (graph[robots[robot].y + j][robots[robot].x])
                        {
                            r1 = robots[robot].id;
                            r2 = graph[robots[robot].y + j][robots[robot].x];
                            goto end;
                        }
                    }
                    robots[robot].y += lenth;
                    graph[robots[robot].y][robots[robot].x] = robots[robot].id;
                }
                else if (robots[robot].dir == W)
                {
                    graph[robots[robot].y][robots[robot].x] = 0;
                    for (int j = 1; j <= lenth; j++)
                    {
                        if (graph[robots[robot].y][robots[robot].x - j])
                        {
                            r1 = robots[robot].id;
                            r2 = graph[robots[robot].y][robots[robot].x - j];
                            goto end;
                        }
                    }
                    robots[robot].x -= lenth;
                    graph[robots[robot].y][robots[robot].x] = robots[robot].id;
                }
                else
                {
                    graph[robots[robot].y][robots[robot].x] = 0;
                    for (int j = 1; j <= lenth; j++)
                    {
                        if (graph[robots[robot].y - j][robots[robot].x])
                        {
                            r1 = robots[robot].id;
                            r2 = graph[robots[robot].y - j][robots[robot].x];
                            goto end;
                        }
                    }
                    robots[robot].y -= lenth;
                    graph[robots[robot].y][robots[robot].x] = robots[robot].id;
                }
            }
        }

    end:
        if (r1 == -1)
            printf("OK\n");
        else if (r2 == -1)
            printf("Robot %d crashes into the wall\n", r1);
        else
            printf("Robot %d crashes into the %d\n", r1, r2);

        while (m > 0)
        {
            int robot;
            char behave;
            int lenth;
            cin >> robot >> behave >> lenth;
            m--;
        }
    }
    return 0;
}