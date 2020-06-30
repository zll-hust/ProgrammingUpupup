#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

// #define LOCAL
typedef long long ll;

ll x1, x2;

struct Line
{
    int id;
    ll k;
    ll b;
    ll y1;
    ll y2;
    Line(int id, ll k, ll b)
    {
        this->id = id;
        this->k = k;
        this->b = b;
        this->y1 = k * x1 + b;
        this->y2 = k * x2 + b;
    }
};

bool cmp1(Line l1, Line l2)
{
    return l1.y1 > l2.y1;
}

bool cmp2(Line l1, Line l2)
{
    return l1.y2 > l2.y2;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    ll n;
    cin >> n;
    cin >> x1 >> x2;
    vector<Line> line;
    for (int i = 0; i < n; i++)
    {
        ll k, b;
        cin >> k >> b;
        line.push_back(Line(i, k, b));
    }

    vector<Line> temp_line(line);
    sort(line.begin(), line.end(), cmp1);
    sort(temp_line.begin(), temp_line.end(), cmp2);

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if ((line[i].id != temp_line[i].id) && (line[i].y1 != temp_line[i].y1) && (line[i].y2 != temp_line[i].y2))
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}