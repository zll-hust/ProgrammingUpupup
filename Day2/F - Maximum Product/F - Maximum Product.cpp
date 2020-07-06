#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

#define LOCAL

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase = 1;
    int lenth;
    while (cin >> lenth)
    {
        int num[20];
        for (int i = 0; i < lenth; i++)
            cin >> num[i];

        int res = 0;
        for (int i = 0; i < lenth; i++)
        {
            int ans = 0;
            int pos = -1;
            bool first = true;
            for (int j = i; j < lenth; j++) // 从第i个字符开始查找
            {
                if (num[j] == 0)
                    break;
                else if (num[j] > 0 && pos == -1) // 如果前面有负数，暂时不乘上
                {
                    if (first)
                    {
                        ans = num[j];
                        first = false;
                    }
                    else
                        ans *= num[j];
                }
                else if(num[j] < 0)
                {
                    if (pos != -1) // pos代表上一个出现负数的位置，-1代表这是第一个
                    {
                        for (int k = pos; k <= j; k++)
                            ans *= num[k];
                        pos = -1;
                    }
                    else
                        pos = j;
                }
            }
            if (ans > res)
                res = ans;
        }

        printf("Case #%d: The maximum product is %d.\n", kase++, res);
    }
    return 0;
}