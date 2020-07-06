#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

// #define LOCAL
typedef long long LL;

bool devide(LL n1, LL n2, LL n3, LL n4)
{
    // cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    if (n1 < 0 || n2 < 0 || n3 < 0 || n4 < 0)
        return false;
    if ((n1 >= 3 || n1 == 0) && (n2 >= 3 || n2 == 0) && // 注意等差数列可以为公差为0的任意长数列，因此超过3个也算true
        (n3 >= 3 || n3 == 0) && (n4 >= 3 || n4 == 0))
        return true;
    if (n1 == 1 || n1 == 2) // 剩下的数种肯定有至少一个数为1或2
    {
        if (devide(n1 - 1, n2 - 1, n3 - 1, n4 - 1)) // 逐步分解让n1减小到0 注意等差数列可以是4个数
            return true;
        if (devide(n1 - 1, n2 - 1, n3 - 1, n4))
            return true;
    }
    if ((n2 == 1 || n2 == 2) || (n3 == 1 || n3 == 2))
    {
        if (devide(n1 - 1, n2 - 1, n3 - 1, n4 - 1))
            return true;
        if (devide(n1 - 1, n2 - 1, n3 - 1, n4))
            return true;
        if (devide(n1, n2 - 1, n3 - 1, n4 - 1)) // n2、n3比n1多一种分解方法，从后半边分解
            return true;
    }
    if (n4 == 1 || n4 == 2)
    {
        if (devide(n1 - 1, n2 - 1, n3 - 1, n4 - 1))
            return true;
        if (devide(n1, n2 - 1, n3 - 1, n4 - 1))
            return true;
    }

    return false;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase;
    cin >> kase;
    while (kase--)
    {
        LL n1, n2, n3, n4;
        cin >> n1 >> n2 >> n3 >> n4;
        if (devide(n1, n2, n3, n4))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}