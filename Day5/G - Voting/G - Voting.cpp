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
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

const int maxn = 200000 + 5;

char a[maxn];
int vis[maxn];

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int n;
	while (cin >> n)
	{
		memset(vis, 0, sizeof(vis));
		scanf("%s", a);
		queue<int> d;
		queue<int> r;
		for (int i = 0; i < n; i++)
			if (a[i] == 'D')
				d.push(i);
			else
				r.push(i);
		while (!d.empty() && !r.empty())
		{
			for (int i = 0; i < n; i++)
			{
				if (vis[i])
					continue;
				if (a[i] == 'D')
				{
					int tmpd = d.front();
					d.pop();
					int tmpr = r.front();
					r.pop();
					vis[tmpr] = 1;
					d.push(tmpd);
				}
				else
				{
					int tmpr = r.front();
					r.pop();
					int tmpd = d.front();
					d.pop();
					vis[tmpd] = 1;
					r.push(tmpr);
				}
				if (d.empty() || r.empty())
					break;
			}
		}
		if (!d.empty())
			printf("D");
		else
			printf("R");
	}
	return 0;
}