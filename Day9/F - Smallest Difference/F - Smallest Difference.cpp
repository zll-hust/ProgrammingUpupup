#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <stack>
// #include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int num[1005];
int n, len;
int ans;

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    cin.get();
    while (n--)
    {
        len = 0;
        string str;
        getline(cin, str);
        stringstream ss(str);
        while(ss >> num[len]) 
            len++;

        if (len == 2) //就两个数
        {
            cout << abs(num[0] - num[1]) << endl;
            continue;
        }

        int n1, n2;
        ans = INT_MAX;
        int mid = len / 2;
        do
        {
            n1 = num[0], n2 = num[mid];
            if (n1 == 0 || n2 == 0)
                continue;
            for (int i = 1; i < mid; i++)
                n1 = n1 * 10 + num[i];
            for (int i = mid + 1; i < len; i++)
                n2 = n2 * 10 + num[i];
            ans = min(ans, abs(n1 - n2));
        } while (next_permutation(num, num + len)); //全排列
        cout << ans << endl;
    }

    return 0;
}