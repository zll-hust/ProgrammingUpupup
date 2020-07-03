#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
char s[100010], t[100010];
int main()
{
    int n, i, j;
    scanf("%d", &n);
    scanf("%s%s", s, t);
    int ans = 0;
    for (i = 0; i < n / 2; i++)
    {
        map<char, int> v; //判断有几种字符，并记录各自个数
        v[s[i]]++;
        v[t[i]]++;
        v[s[n - i - 1]]++;
        v[t[n - i - 1]]++;
        if (v.size() >= 2)
        {
            if (v.size() == 2) //有两种字符
            {
                if (v[s[i]] != 2) //（1，3）情况
                    ans++;
            }
            else if (v.size() == 3) //有三种字符
            {
                if (s[i] == s[n - i - 1]) // 因为是先改变再交换，且只能改变s字符串，所以这种情况下要改变两个
                    ans += 2;
                else //反之，改变一个
                    ans++;
            }
            else //有四种字符
                ans += 2;
        }
    }
    if (n % 2)                    //奇数
        if (s[n / 2] != t[n / 2]) //判断中间的两个字符是否相等
            ans++;
    printf("%d\n", ans);
}
