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
map<int, int> primes;
void gcd_split(int n)
{
	set<int> p;
	for (int i = 2; i <= n; i++)
	{
		while (n != i)
		{
			if (n % i == 0)
			{
				p.insert(i);
				n = n / i;
			}
			else
				break;
		}
	}
    p.insert(n);
	for(set<int>::iterator it = p.begin(); it != p.end(); it++)
		primes[*it]++;
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		gcd_split(temp);
	}
	int ans = 0;
	for(map<int, int>::iterator it = primes.begin(); it != primes.end(); it++)
		if(it->second > ans) ans = it->second;
	cout << ans;
	return 0;
}