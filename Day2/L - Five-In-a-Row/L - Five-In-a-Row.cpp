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

int lenth = 10;
char graph[15][15];

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    for (int j = 1; j <= 10; j++)
        graph[0][j] = 'O'; // 'O'是对面的棋子，等同于代表墙体
    for (int i = 1; i <= 10; i++)
    {
        graph[i][0] = 'O';
        for (int j = 1; j <= 10; j++)
            graph[i][j] = '.'; // '.'代表空
        graph[i][10 + 1] = 'O';
    }
    for (int j = 1; j <= 10; j++)
        graph[10 + 1][j] = 'O';

    for (int i = 1; i <= 10; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= 10; j++)
            graph[i][j] = str[j - 1];
    }

    bool flag = false;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (graph[i][j] != '.')
                continue;
            // 判断左右
            int left = 0, right = 0;
            for (int k = 1;; k++)
            {
                if (graph[i][j - k] == 'X')
                    left++;
                else
                    break;
            }
            for (int k = 1;; k++)
            {
                if (graph[i][j + k] == 'X')
                    right++;
                else
                    break;
            }
            if ((left + right + 1) > 4)
            {
                flag = true;
                goto end;
            }

            // 判断上下
            int up = 0, down = 0;
            for (int k = 1;; k++)
            {
                if (graph[i - k][j] == 'X')
                    down++;
                else
                    break;
            }
            for (int k = 1;; k++)
            {
                if (graph[i + k][j] == 'X')
                    up++;
                else
                    break;
            }
            if ((up + down + 1) > 4)
            {
                flag = true;
                goto end;
            }

            // 判断左侧斜向上、下
            up = 0, down = 0;
            for (int k = 1;; k++)
            {
                if (graph[i - k][j + k] == 'X')
                    down++;
                else
                    break;
            }
            for (int k = 1;; k++)
            {
                if (graph[i + k][j - k] == 'X')
                    up++;
                else
                    break;
            }
            if ((up + down + 1) > 4)
            {
                flag = true;
                goto end;
            }

            // 判断右侧斜向上、下
            up = 0, down = 0;
            for (int k = 1;; k++)
            {
                if (graph[i - k][j - k] == 'X')
                    down++;
                else
                    break;
            }
            for (int k = 1;; k++)
            {
                if (graph[i + k][j + k] == 'X')
                    up++;
                else
                    break;
            }
            if ((up + down + 1) > 4)
            {
                flag = true;
                goto end;
            }
        }
    }

end:
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}