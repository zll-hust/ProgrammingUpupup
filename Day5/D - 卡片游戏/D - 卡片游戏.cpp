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
	while (n--)
	{
		string str;
		cin >> str;
		vector<int> num;
		num.push_back(int(str[0]) - '0');
		for (int i = 1; i < str.size(); i++)
		{
			int temp = str[i] - '0';
			for (int j = 0; j < str.size(); j++)
			{
				if(j < (str.size() - 1) && temp == num[j])
					continue;
				else if (!num[j] || (temp < num[j] && temp))
					num.insert(num.begin(), temp);
				else
					num.push_back(temp);
				break;
			}
		}
		int ans = 0;
		for (vector<int>::iterator it = num.begin(); it != num.end(); it++)
			ans = ans * 10 + *it;
		printf("%d\n", ans);
	}
	return 0;
}