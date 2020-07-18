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
#define LOCAL

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

const int maxn = 100 + 5;
int n, m;
int min_dis[maxn][maxn];

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			min_dis[i][j] = 10000;
		min_dis[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		min_dis[v - 1][u - 1] =  min_dis[u - 1][v - 1] = min(min_dis[u - 1][v - 1], w);
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				min_dis[i][j] = min(min_dis[i][j], min_dis[i][k] + min_dis[k][j]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << min_dis[i][j] << " ";
		cout << endl;
	}
	return 0;
}