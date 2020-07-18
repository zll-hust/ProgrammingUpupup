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
#define INF 1e11
#define LOCAL

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

const int maxn = 100000 + 5;
int n, m, k, b[1000];
long long mp[805][805], d[maxn];
struct node
{
	int u, v, w;
} a[maxn];
bool cmp(node x, node y) { return x.w < y.w; }

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> a[i].u >> a[i].v >> a[i].w;
	sort(a + 1, a + m + 1, cmp);

	int cnt = 0;
	for (int i = 1; i <= min(m, k); i++)
		b[++cnt] = a[i].u, b[++cnt] = a[i].v;
	sort(b + 1, b + cnt + 1);
	
	cnt = unique(b + 1, b + cnt + 1) - b - 1;
	for (int i = 1; i <= cnt; i++)
		for (int j = 1; j <= cnt; j++)
			mp[i][j] = INF;
	
	for (int i = 1; i <= min(m, k); i++)
	{
		int u = lower_bound(b, b + cnt + 1, a[i].u) - b;
		int v = lower_bound(b, b + cnt + 1, a[i].v) - b;
		mp[u][v] = mp[v][u] = a[i].w;
	}
	
	for (int q = 1; q <= cnt; q++)
		for (int i = 1; i <= cnt; i++)
			for (int j = 1; j <= cnt; j++)
				if (mp[i][j] > mp[i][q] + mp[q][j])
					mp[i][j] = mp[i][q] + mp[q][j];
	
	int cnt1 = 0;
	for (int i = 1; i <= cnt; i++)
		for (int j = i + 1; j <= cnt; j++)
			if (mp[i][j] != INF)
				d[++cnt1] = mp[i][j];

	sort(d, d + cnt1 + 1);
	printf("%lld\n", d[k]);
	return 0;
}