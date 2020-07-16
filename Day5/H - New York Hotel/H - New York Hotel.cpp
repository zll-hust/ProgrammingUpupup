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

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	int hotel, restaurant;
	scanf("%d", &hotel);
	ll tmp1, tmp2;

	ll ff, zz, fz, zf;
	scanf("%lld %lld", &tmp1, &tmp2);
	ff = -tmp1 - tmp2;
	zz = tmp1 + tmp2;
	fz = -tmp1 + tmp2;
	zf = tmp1 - tmp2;
	for (int i = 1; i < hotel; ++i)
	{
		scanf("%lld %lld", &tmp1, &tmp2);
		ff = max(ff, -tmp1 - tmp2);
		zz = max(zz, tmp1 + tmp2);
		fz = max(fz, -tmp1 + tmp2);
		zf = max(zf, tmp1 - tmp2);
	}

	scanf("%d", &restaurant);
	ll result = INT_MAX;
	int flag;
	for (int i = 0; i < restaurant; ++i)
	{
		scanf("%lld %lld", &tmp1, &tmp2);
		ll tmp = max(max(tmp1 + tmp2 + ff, tmp1 - tmp2 + fz), max(-tmp1 + tmp2 + zf, -tmp1 - tmp2 + zz));
		if (tmp < result)
		{
			result = tmp;
			flag = i + 1;
		}
	}
	printf("%lld\n%d\n", result, flag);
	return 0;
}