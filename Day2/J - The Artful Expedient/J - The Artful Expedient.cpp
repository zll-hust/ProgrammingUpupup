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

int x[2005];
int y[2005];
int bucket[5000005];
// set<int> num;

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    memset(bucket, 0, sizeof(bucket));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
        // num.insert(x[i]);
        bucket[x[i]] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
        // num.insert(y[i]);
        bucket[y[i]] = 1;
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // if(num.find(x[i] ^ y[i]) != num.end()) res++;
            if(bucket[x[i] ^ y[i]]) res++;
        }
    }

    if(res % 2) cout << "Koyomi" << endl;
    else cout << "Karen"<<endl;

    return 0;
}