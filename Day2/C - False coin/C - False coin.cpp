#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n, m; //n为硬币数量，m为天平数量
    scanf("%d%d", &n, &m);
    int *coins = new int[n + 5];
    int *lightCoins = new int[n + 5];
    int *heavyCoins = new int[n + 5];
    memset(coins, 0, sizeof(int) * (n + 5));
    memset(lightCoins, 0, sizeof(int) * (n + 5));
    memset(heavyCoins, 0, sizeof(int) * (n + 5));
    int unequalNr = 0;
    while (m-- > 0)
    {
        int i;
        cin >> i;
        int *left = new int[i + 5];
        int *right = new int[i + 5];
        for (int j = 0; j < i; j++)
            cin >> left[j];
        for (int j = 0; j < i; j++)
            cin >> right[j];
        char res;
        cin >> res;
        if (res == '=')
        {
            for (int j = 0; j < i; j++)
            {
                coins[left[j]] = 1;
                coins[right[j]] = 1;
            }
        }
        else if (res == '>')
        {
            unequalNr++;
            for (int j = 0; j < i; j++)
            {
                lightCoins[right[j]]++;
                heavyCoins[left[j]]++;
            }
        }
        else
        {
            unequalNr++;
            for (int j = 0; j < i; j++)
            {
                lightCoins[left[j]]++;
                heavyCoins[right[j]]++;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << coins[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << lightCoins[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << heavyCoins[i] << " ";
    // }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!coins[i] && (lightCoins[i] == unequalNr || heavyCoins[i] == unequalNr)){
            cout << i << endl;
            sum++;
        }
    }
    if(!sum)
        cout << '0' << endl;

    return 0;
}