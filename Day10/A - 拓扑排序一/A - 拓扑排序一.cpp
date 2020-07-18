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
int deg[maxn];
int vis[maxn];
vector<int> g[maxn];
queue<int> q;
int n, m;

bool topological()
{
	for (int i = 1; i <= n; i++)
	{
		if(!deg[i])
		{
			vis[i] = 1;
			q.push(i);
		}
	}
	int num = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		num++;
		for(auto to:g[now])
		{
			if(vis[to])
				continue;
			else
			{
				deg[to]--;
				if(!deg[to])
				{
					vis[to] = 0;
					q.push(to);
				}
			}
		}
	}
	if(num == n)
		return true;
	else
		return false;
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		memset(vis, 0, sizeof(vis));
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < n; i++)
			g[i].clear();
		while (!q.empty())
			q.pop();
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			deg[v]++;
		}
		if(topological())
			cout << "Correct" << endl;
		else
			cout << "Wrong" << endl;
	}
	
	return 0;
}