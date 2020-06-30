#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// #define LOCAL

bool cmp1(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> left;
    vector<pair<int, int>> right;

    for (int i = 0; i < n; i++)
    {
        int pos;
        int appleNr;
        scanf("%d %d", &pos, &appleNr);
        if (pos > 0)
            right.push_back(make_pair(pos, appleNr));
        else
            left.push_back(make_pair(pos, appleNr));
    }

    sort(left.begin(), left.end(), cmp2);
    sort(right.begin(), right.end(), cmp1);

    int sum = 0;
    int size;
    if (left.size() < right.size())
    {
        size = left.size();
        sum += right[size].second;
    }
    else if (left.size() > right.size())
    {
        size = right.size();
        sum += left[size].second;
    }
    else
        size = left.size();

    for (int i = 0; i < size; i++)
        sum += left[i].second + right[i].second;
    printf("%d", sum);
    return 0;
}