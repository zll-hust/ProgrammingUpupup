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
ll arc[maxn];

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> arc[i];
	sort(arc, arc + n);
	bool ans = false;
	ll a1 = arc[0], a2 = arc[1], a3 = arc[2];
	if (a1 + a2 > a3)
	{
		ans = true;
		goto end;
	}
	for (int i = 3; i < n; i++)
	{
		a1 = a2;
		a2 = a3;
		a3 = arc[i];
		if (a1 + a2 > a3)
		{
			ans = true;
			break;
		}
	}
	end:
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}