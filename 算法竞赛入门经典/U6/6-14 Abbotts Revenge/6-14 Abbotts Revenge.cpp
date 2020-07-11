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

struct Node
{
    int dir;
    int r; //row
    int c; //col
    Node()
    {
        r = 0;
        c = 0;
        dir = 0;
    }

    Node(int r, int c, int dir)
    {
        this->r = r;
        this->c = c;
        this->dir = dir;
    }
};

const char *dirs = "NESW"; //顺时针旋转
const char *turns = "FLR";
int dir_id(char c) { return strchr(dirs, c) - dirs; }
int turn_id(char c) { return strchr(turns, c) - turns; }
int has_edge[15][15][10][10]; //r,c,dir,trun是否可以行走
int d[15][15][10]; //最短路是否经过
Node pre[15][15][10]; //前一个点
int r_end, c_end, r1, c1, r_start, c_start, dir;
int inside[15][15];

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
Node walk(const Node &u, int turn)
{
    int dir = u.dir;
    if (turn == 1)
        dir = (dir + 3) % 4; //逆时针
    if (turn == 2)
        dir = (dir + 1) % 4; //顺时针
    return Node(u.r + dr[dir], u.c + dc[dir], dir);
}

void print_ans(Node);
void solve() //bfs
{
    queue<Node> q;
    memset(d, -1, sizeof(d));
    Node u(r1, c1, dir);
    d[u.r][u.c][u.dir] = 0;
    q.push(u);
    while (!q.empty())
    {
        Node u = q.front();
        q.pop();
        if (u.r == r_end && u.c == c_end) //终点判断
        {
            print_ans(u);
            return;
        }
        for (int i = 0; i < 3; i++) //四个方向
        {
            Node v = walk(u, i);
            if (has_edge[u.r][u.c][u.dir][i] && inside[v.r][v.c] && d[v.r][v.c][v.dir] < 0) //存在边，存在点，未循环(循环则impossible)
            {
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                pre[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    printf("No Solution Possible\n");
}

void print_ans(Node u) //从目标结点逆序追溯到初始结点
{
    vector<Node> nodes;
    while(true)
    {
        nodes.push_back(u);
        if (d[u.r][u.c][u.dir] == 0)
            break;
        u = pre[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r_start, c_start, dir)); //打印解，每行10个
    int cnt = 0;
    for (int i = nodes.size() - 1; i >= 0; i--)
    {
        if (cnt % 10 == 0)
            printf(" ");
        printf(" (%d,%d)", nodes[i].r, nodes[i].c);
        if (++cnt % 10 == 0)
            printf("\n");
    }
    if (nodes.size() % 10 != 0)
        printf("\n");
}

int find(const char *str, char v)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] == v)
            return i;
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    char tag[20];
    while (scanf("%s", &tag) == 1)
    {
        if (tag[0] == 'E' && tag[1] == 'N' && tag[2] == 'D')
            break;
        printf("%s", tag);
        memset(d, -1, sizeof(d));
        memset(inside, -1, sizeof(inside));
        memset(has_edge, 0, sizeof(has_edge));
        char firstd;
        scanf("%d %d %c %d %d\n", &r_start, &c_start, &firstd, &r_end, &c_end);
        inside[r_start][c_start] = 1;
        inside[r_end][c_end] = 1;
        dir = dir_id(firstd);
        r1 = r_start + dr[dir];
        c1 = c_start + dc[dir];
        while (true)
        {
            int r, c;
            scanf("%d", &r);
            if (r == 0)
                break;
            scanf("%d", &c);
            inside[r][c] = 1;
            char temp[20];
            memset(temp, 0, sizeof(temp));
            while (scanf("%s", &temp) == 1 && temp[0] != '*')
            {
                int *temp2 = has_edge[r][c][find(dirs, temp[0])];
                int len = strlen(temp);
                for (int i = 1; i < len; i++)
                    temp2[find(turns, temp[i])] = 1;
            }
        }
        solve();
    }

    return 0;
}