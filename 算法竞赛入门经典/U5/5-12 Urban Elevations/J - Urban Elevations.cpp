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
// #define LOCAL

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

struct Building
{
    int id;
    double x, y, w, d, h;
    bool operator < (const Building& other) const
    {
        if (x != other.x)
            return x < other.x;
        else
            return y < other.y;
    }
} b[105];

int n;
double x[300];

// 判断建筑id在mid_x所在区间内
bool is_in_section(int id, int mid_x)
{
    return (b[id].x < mid_x && (b[id].x + b[id].w) > mid_x);
}

// 判断建筑id在mid_x处是否能被看见
bool is_visible(int id, double mid_x)
{
    if (!is_in_section(id, mid_x))
        return false;
    for (int i = 0; i < n; i++)
    {
        if (is_in_section(i, mid_x) &&
            (b[i].y < b[id].y && b[i].h >= b[id].h))
            return false;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase = 1;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
            b[i].id = i + 1;
            x[2 * i] = b[i].x;
            x[2 * i + 1] = b[i].x + b[i].w;
        }
        sort(x, x + 2 * n);
        sort(b, b + n);
        int m = unique(x, x + n * 2) - x; //x坐标排序后去重，得到m个坐标

        printf("For map #%d, the visible buildings are numbered as follows:\n", kase++);
        cout << b[0].id;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (is_visible(i, (x[j] + x[j + 1]) / 2))
                {
                    printf(" %d", b[i].id);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}