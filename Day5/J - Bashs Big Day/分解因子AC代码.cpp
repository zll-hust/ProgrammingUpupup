#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 100010;
int s[INF] = {0};
int main()
{
    int n;
    cin >> n;
    int m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        int j = 1;
        for (j = 1; j * j < m; j++) //从1开始是对每个数都让自己这个数量从0变为1
        {
            if (m % j == 0)
            {
                s[j]++;
                s[m / j]++; //因子++
            }
        }
        if (j * j == m)
        {
            s[j]++;
        }
    }
    int ans = 1;
    for (int i = 2; i < INF; i++)
    {
        ans = max(ans, s[i]);
    }
    cout << ans << endl;
    return 0;
}