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

set<LL> nums;

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
        int x, a = 5001, b, c;
        cin >> x;
        for (int i = 0; i <= 5000; i++)
        {
            for (int j = -5000; j <= 5000; j++)
            {
                LL sum = x - pow(i, 3) - pow(j, 3);
                int k = pow((double)sum, (double)1 / 3);
                if(pow(k, 3) == sum)
                {
                    a = i;
                    b = j;
                    c = k;
                    goto end;
                }
                //cout << "running..." << endl;
            }
        }
    end:
        if (a != 5001)
            printf("%d %d %d\n", a, b, c);
        else
            cout << "impossible" << endl;
    }

    return 0;
}