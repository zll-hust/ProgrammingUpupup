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
#define LOCAL

int n, m;
int ct;
vector<int> arc[105];
int vis[100];

bool dfs(int now, int pre)
{
	vis[now] = 1;
	if (arc[now].size() != 2)
		return false;
	int fg = 0;
	for (auto to : arc[now])
	{
		if(to == pre)
			continue;
		if (!vis[to])
		{
			if (dfs(to, now))
				return true;
			else
				return false;
		}
		else if (vis[to] && arc[to].size() == 2)
			return true;
	}
	return false;
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int ct = 0;
	scanf("%d %d", &n, &m);
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		arc[u].push_back(v);
		arc[v].push_back(u);
	}

	ct = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (dfs(i, -1))
				ct++;
		}
	}
	printf("%d\n", ct);

	return 0;
}