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

const int maxn = 100 + 5;
pii cus[maxn];

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int n;
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			cus[i].first = b;
			cus[i].second = a;
		}
		sort(cus, cus + n);
		int temp = cus[0].first, sum = 1;
		for (int i = 1; i < n; i++)
		{
			if (cus[i].second >= temp)
			{
				sum++;
				temp = cus[i].first;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}