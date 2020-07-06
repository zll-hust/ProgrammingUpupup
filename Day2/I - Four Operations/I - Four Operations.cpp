#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
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
    int kase;
    int x = 1;
    cin >> kase;
    while (x <= kase)
    {
        LL res, sum;
        string str;
        cin >> str;
        LL a = 0, b = 0, c = 0, d = 0, e = 0;

        // case 1: e取一位数字, a取一位数
        e = str[str.length() - 1] - '0';
        d = str[str.length() - 2] - '0';
        c = str[str.length() - 3] - '0';
        a = str[0] - '0';
        for (int i = 1; i < str.length() - 3; i++)
        {
            b *= 10;
            b += str[i] - '0';
        }
        res = a + b - c * d / e;

        a = 0, b = 0, c = 0, d = 0, e = 0;
        // case 2: e取一位数字, b取一位数
        e = str[str.length() - 1] - '0';
        d = str[str.length() - 2] - '0';
        c = str[str.length() - 3] - '0';
        b = str[str.length() - 4] - '0';
        for (int i = 0; i < str.length() - 4; i++)
        {
            a *= 10;
            a += str[i] - '0';
        }
        sum = a + b - c * d / e;
        if(res < sum) res = sum;

        a = 0, b = 0, c = 0, d = 0, e = 0;
        // case 3: e取两位数字, b取一位数
        e = (str[str.length() - 2] - '0') * 10 + str[str.length() - 1] - '0';
        d = str[str.length() - 3] - '0';
        c = str[str.length() - 4] - '0';
        b = str[str.length() - 5] - '0';
        for (int i = 0; i < str.length() - 5; i++)
        {
            a *= 10;
            a += str[i] - '0';
        }
        sum = a + b - c * d / e;
        if(res < sum) res = sum;

        a = 0, b = 0, c = 0, d = 0, e = 0;
        // case 4: e取两位数字, a取一位数
        e = (str[str.length() - 2] - '0') * 10 + str[str.length() - 1] - '0';
        d = str[str.length() - 3] - '0';
        c = str[str.length() - 4] - '0';
        a = str[0] - '0';
        for (int i = 1; i < str.length() - 4; i++)
        {
            b *= 10;
            b += str[i] - '0';
        }
        sum = a + b - c * d / e;
        if(res < sum) res = sum;

        cout << "Case #" << x++ << ": " << res <<endl;
    }
}