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
typedef pair<int, int> pii;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
#define LOCAL

string banners[10];
char ki[6] = {'h', 'a', 'r', 'b', 'i', 'n'};
int vis[6];

bool dfs(int ban)
{
    // 边界判断
    bool flag = true;
    for(auto exist: vis)
        if(!exist)
        {
            flag = false;
            break;
        }
    if(flag) 
        return true;

    for(int i = 0; i < banners[ban].size(); i++)
    {
        for(int j = 0; j < 6; j++)
            if (banners[ban][i] == ki[j])
            {
                vis[j] = 1;
                if(dfs(ban + 1))
                    return true;
                else
                {
                    vis[j] = 0;
                    break;
                }
            }
    }
    return false;
}



int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    while(n--){
        for(int i = 0; i < 6; i++)
            cin >> banners[i];
        memset(vis, 0, sizeof(vis));
        if(dfs(0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}