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
	pii node[4];
	for(int i = 0; i < 3; i++)
		cin >> node[i].first >> node[i].second;
	cout << 3 << endl;
	printf("%d %d \n",node[0].first + node[1].first - node[2].first, node[0].second + node[1].second - node[2].second);
	printf("%d %d \n",node[1].first + node[2].first - node[0].first, node[1].second + node[2].second - node[0].second);
	printf("%d %d \n",node[2].first + node[0].first - node[1].first, node[2].second + node[0].second - node[1].second);
	return 0;
}