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

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int n;
	cin >> n;
	int n2 = 0, n3 = 0;
	while (n)
	{
		if(n % 2)
		{
			n3++;
			n -= 3;
		}
		else
		{
			n2++;
			n -= 2;
		}
	}
	printf("%d\n", n2 + n3);
	for(int i = 0; i < n2; i++)
		printf("%d ", 2);
	for(int i = 0; i < n3; i++)
		printf("%d ", 3);
	return 0;
}