#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <math.h>
using namespace std;

typedef long long LL;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    int n;
    while (cin >> n)
    {
        int sum = 0;
        vector<pair<int, int>> num_pair;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (!(n * i % (i - n)))
            {
                int j = n * i / (i - n);
                num_pair.push_back(make_pair(j, i));
            }
        }
        cout << num_pair.size() << endl;
        for (vector<pair<int, int>>::iterator it = num_pair.begin(); it != num_pair.end(); it++)
        {
            printf("1/%d = 1/%d + 1/%d\n", n, (*it).first, (*it).second);
        }
    }

    return 0;
}