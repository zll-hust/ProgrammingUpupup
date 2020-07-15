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

const int maxn = 1000 + 5;
int J[maxn];
int F[maxn];
pdi deg[maxn];

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int m, n;
	while (cin >> m >> n && m != -1)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> J[i] >> F[i];
			deg[i] = {(double)J[i] / (double)F[i], i};
		}
		sort(deg, deg + n);
		reverse(deg, deg + n);
		int cnt = 0;
		double sum = 0;
		while(m)
		{
			if(m >= F[deg[cnt].second])
			{
				sum += J[deg[cnt].second];
				m -= F[deg[cnt].second];
				cnt++;
			}
			else
			{
				sum += deg[cnt].first * m;
				break;
			}
		}
		printf("%.3lf\n", sum);
	}
	return 0;
}