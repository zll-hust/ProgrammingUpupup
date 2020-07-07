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

int numbers[5000005];
// set<int> num;

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    sort(numbers, numbers + n);
    int sum = 0;
    for(int i = 0; i < n - 1; i++)
        sum += numbers[i];
    int ans = numbers[n - 1] - sum + 1;
    cout << ans << endl;
    return 0;
}