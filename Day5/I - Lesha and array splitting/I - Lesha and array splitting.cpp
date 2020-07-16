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
int num[maxn];
pii area[maxn];

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int n, cnt = 0, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		if(num[i])
			flag = 1;
	}
	if(!flag)
	{
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (num[i])
		{
			area[cnt].first = area[cnt].second = i;
			cnt++;
		}
		else
		{
			if (cnt > 0)
				area[cnt - 1].second++;
			else
			{
				area[0].first = 0;
				for (i = i + 1; i < n; i++)
				{
					if (num[i])
					{
						area[0].second = i;
						cnt++;
						break;
					}
				}
			}
		}
	}
	cout << "YES" << endl;
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		printf("%d %d\n", area[i].first + 1, area[i].second + 1);
	return 0;
}