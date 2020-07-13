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
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

int n;
vector<int> arc[200005];
int a[200005];

int bfs(int m)
{
	queue<pii> q;
	q.push({ m, 0 });
	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		if (now.first != m && (a[now.first] % 2 != a[m] % 2))
			return now.second;
		for (auto to : arc[now.first])
		{
			q.push({ to, now.second + 1 });
		}
	}

	return -1;
}
int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int ans;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		arc[i].clear();
		if ((i - a[i]) > 0 && (i - a[i]) <= n)
			arc[i].push_back(i - a[i]);
		if ((i + a[i]) > 0 && (i + a[i]) <= n)
			arc[i].push_back(i + a[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		ans = bfs(i);
		printf("%d ", ans);
	}

	return 0;
}