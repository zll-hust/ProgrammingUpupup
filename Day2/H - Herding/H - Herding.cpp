#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

typedef long long LL;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

struct Point
{
    double x;
    double y;

    Point()
    {
        this->x = -1;
        this->y = -1;
    }
} points[105];

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase;
    cin >> kase;
    while (kase--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        double min = INT_MAX;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                {
                    // 向量叉乘计算面积: S = |x1y2 - x1y3 + x2y3 - x2y1 + x3y1 - x3y2| / 2
                    double s = abs(points[i].x * points[j].y - points[i].x * points[k].y +
                               points[j].x * points[k].y - points[j].x * points[i].y +
                               points[k].x * points[i].y - points[k].x * points[j].y) / 2.0;
                    if (s < min && s > 0.0) {
                        min = s;
                        // cout << i << j << k << endl;
                    }
                }
        if(min == INT_MAX) cout << "Impossible" << endl;
        else printf("%0.2f\n", min);
    }
    return 0;
}