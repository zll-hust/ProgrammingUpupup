#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
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

int n;
int vis[25];
int order[105];
ll num[105];

bool dfs(int cur, int m)
{
	if (n == m)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", num[order[i]]);
		cout << endl;
		return true;
	}

	ll x1 = num[cur] * 2, x2 = 0;
	if (num[cur] % 3 == 0)
		x2 = num[cur] / 3;

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			if (num[i] == x1 || (x2 && num[i] == x2))
			{
				vis[i] = 1;
				order[m] = i;
				if (dfs(i, m + 1))
					return true;
				vis[i] = 0;
			}
		}
	}
	// cout << "sorry, not find!" << endl;
	return false;
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	memset(vis, 0, sizeof(vis));
	memset(order, 0, sizeof(order));
	for (int i = 0; i < n; i++)
	{
		vis[i] = 1;
		order[0] = i;
		dfs(i, 1);
		vis[i] = 0;
	}
	return 0;
}