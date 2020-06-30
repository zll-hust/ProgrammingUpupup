#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// #define LOCAL
// Wrong answer on test 5 速度明明很快的说

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    long long n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    long long r1_pow = 0, r2_pow = 0;

    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        long long dis_pow1 = pow(x - x1, 2) + pow(y - y1, 2);
        if (dis_pow1 > r1_pow)
        {
            long long dis_pow2 = pow(x - x2, 2) + pow(y - y2, 2);
            if (dis_pow2 > r2_pow)
                if ((dis_pow1 - r1_pow) > (dis_pow2 - r2_pow))
                {
                    r2_pow = dis_pow2;
                }
                else
                {
                    r1_pow = dis_pow1;
                }
        }
    }

    cout << (r1_pow + r2_pow) << endl;
    return 0;
}