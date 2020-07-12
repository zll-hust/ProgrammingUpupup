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
typedef pair<int, int> pii;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

int n, m;
char graph[205][205];
int sx, sy, ex, ey;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node
{
    int x, y, step;
    friend bool operator<(node a, node b)
    {
        return a.step > b.step;
    }
} a, temp;
int bfs()
{
    a.x = sx;
    a.y = sy;
    a.step = 0; //初始化从'r'开始走的位置
    priority_queue<node> q;
    q.push(a); //入栈
    while (!q.empty())
    {
        a = q.top(); //取栈顶赋予a
        q.pop();
        if (a.x == ex && a.y == ey)
            return a.step; //判断是否遇到了'a'
        for (int i = 0; i < 4; i++) //进行探索上下左右
        {
            temp.x = a.x + dir[i][0];
            temp.y = a.y + dir[i][1];
            if (temp.x < n && temp.x >= 0 && temp.y < m && temp.y >= 0 && graph[temp.x][temp.y] != '#') //判断是否能走
            {
                if (graph[temp.x][temp.y] == '.' || graph[temp.x][temp.y] == 'a')
                    temp.step = a.step + 1;
                else
                    temp.step = a.step + 2;
                graph[temp.x][temp.y] = '#';
                q.push(temp);
            }
        }
    }
    return 0;
}
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int ans;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%s", graph[i]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j] == 'r')
                {
                    sx = i;
                    sy = j;
                }
                if (graph[i][j] == 'a')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        ans = bfs();
        if (ans)
            printf("%d\n", ans);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}