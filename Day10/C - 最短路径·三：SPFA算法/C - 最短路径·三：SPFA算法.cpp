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

const int maxn = 100000 + 5;
int vis[maxn];
int dist[maxn];
vector<pii> g[maxn];
queue<int> q;
int n, m;

void SPFA(int start)
{
	for (int i = 0; i < n; i++)
		dist[i] = 10000;
	queue<int> q;
	dist[start] = 0;
	vis[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		vis[v] = false;

		for (int i = 0; i < g[v].size(); i++)
		{
			int nex = g[v][i].first;
			if (g[v][i].second > 0 && dist[nex] > dist[v] + g[v][i].second)
			{
				dist[nex] = dist[v] + g[v][i].second;
				if (vis[nex] == false)
				{
					q.push(nex);
					vis[nex] = true;
				}
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		g[i].clear();
	while (!q.empty())
		q.pop();
	int s, e;
	cin >> n >> m >> s >> e;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	SPFA(s - 1);
	cout << dist[e - 1];
	return 0;
}