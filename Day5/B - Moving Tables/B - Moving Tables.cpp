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

const int maxn = 300 + 5;

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int kase;
	int n;
	cin >> kase;
	while (kase--)
	{
		cin >> n;
		vector<pii > mov;
		for(int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			if (b > a)
				swap(a, b);
			mov.push_back({a, b});
		}
		sort(mov.begin(), mov.end());
		int cnt = 0;
		while(!mov.empty())
		{
			int temp = mov[0].second;
			mov.erase(mov.begin());
			for(vector<pii>::iterator it = mov.begin(); it != mov.end(); it++)
			{
				if((*it).first > temp)
				{
					temp = (*it).second;
					mov.erase(it);
					it--;
				}
			}
			cnt += 10;
		}
		printf("%.d\n", cnt);
	}
	return 0;
}