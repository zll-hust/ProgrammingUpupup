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

vector<ll> usb, ps2;

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int n, nu, np, nb;
	scanf("%d%d%d%d", &nu, &np, &nb, &n);
	for (int i = 0; i < n; i++)
	{
		ll price;
		string type;
		cin >> price >> type;
		if (type[0] == 'U')
			usb.push_back(price);
		else
			ps2.push_back(price);
	}
	sort(usb.begin(), usb.end());
	sort(ps2.begin(), ps2.end());
	ll sum = 0;
	int cnt = 0;
	for (int i = 0; i < nu && i < usb.size(); i++)
	{
		sum += usb[i];
		cnt++;
	}
	for (int i = 0; i < np && i < ps2.size(); i++)
	{
		sum += ps2[i];
		cnt++;
	}
	for (int i = 0; i < nb; i++)
	{
		if (nu < usb.size() && np < ps2.size())
		{
			if (usb[nu] > ps2[np])
				sum += ps2[np++];
			else
				sum += usb[nu++];
			cnt ++;
		}
		else if(nu < usb.size())
		{
			sum += usb[nu++];
			cnt++;
		}
		else
		{
			sum += ps2[np++];
			cnt++;
		}
	}
	printf("%d %lld", cnt, sum);
	return 0;
}