#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

typedef long long ll;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
#define LOCAL

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int arr[1005];

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        while (true)
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
                if (arr[0] == 0)
                    goto end;
            }
            stack<int> s;
            int step = 0;
            bool fg = false;
            for (int i = 1; i <= n; i++)
            {
                s.push(i);
                if (s.top() == arr[step])
                {
                    s.pop();
                    step++;
                    fg = true;
                }
                while (fg)
                {
                    if (!s.empty() && s.top() == arr[step])
                    {
                        s.pop();
                        step++;
                    }
                    else
                        fg = false;
                }
            }
            if (s.empty())
                printf("Yes\n");
            else
                printf("No\n");
        }
        end:
        cout << endl;
    }
    return 0;
}