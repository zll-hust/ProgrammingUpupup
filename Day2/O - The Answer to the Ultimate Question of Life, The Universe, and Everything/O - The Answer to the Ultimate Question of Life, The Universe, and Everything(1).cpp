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
//#define LOCAL

set<LL> nums;

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    int lenth = 5000;
    int n;
    cin >> n;
    for (int i = -lenth; i <= lenth; i++)
        nums.insert(pow(i, 3));
    while (n--)
    {
        int x, a = lenth + 10, b, c;
        cin >> x;
        for (set<LL>::iterator it = nums.find(0); it != nums.end(); it++)
        {
            for (set<LL>::iterator it2 = nums.begin(); it2 != nums.end(); it2++)
            {
                set<LL>::iterator it3 = nums.find(x - *it - *it2);
                if (it3 != nums.end())
                {
                    a = distance(nums.begin(), it) - lenth;
                    b = distance(nums.begin(), it2) - lenth;
                    c = distance(nums.begin(), it3) - lenth;
                    goto end;
                }
                //cout << "running..." << endl;
            }
        }
        end:
        if (a != (lenth + 10))
            printf("%d %d %d\n", a, b, c);
        else
            cout << "impossible" << endl;
    }

    return 0;
}