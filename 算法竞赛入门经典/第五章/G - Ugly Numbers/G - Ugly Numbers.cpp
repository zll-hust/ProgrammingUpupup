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

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

priority_queue<ll, vector<ll>, greater<ll>> pq;
set<ll> s;

void is_new_ugly(ll y)
{
    if (!s.count(y))
    {
        pq.push(y);
        s.insert(y);
    }
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    pq.push(1);
    s.insert(1);
    for(int i = 1; i < 1500; i++)
    {
        ll x = pq.top();
        pq.pop();
        ll y1 = x * 2;
        ll y2 = x * 3;
        ll y3 = x * 5;
        is_new_ugly(y1);
        is_new_ugly(y2);
        is_new_ugly(y3);
    }
    cout << "The 1500'th ugly number is " << pq.top() << "."<< endl;
    return 0;
}