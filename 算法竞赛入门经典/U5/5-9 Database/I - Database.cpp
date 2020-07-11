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
// #define LOCAL

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

vector<int> table[10005];
map<string, int> id_map; // 字符串->id
int getId(string s)      // 获取字符串id，若已存在，直接返回，否则分配id
{
    if (!id_map.count(s))
        id_map[s] = id_map.size(); // 不存在
    return id_map[s];
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        cin.get();
        id_map.clear();
        for (int i = 0; i < n; i++)
        {
            string s, st;
            getline(cin, s);
            stringstream input(s);
            while (getline(input, st, ','))
                table[i].push_back(getId(st));
        }
        bool isPNF = true;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                map<pair<int, int>, int> pos; // 两列对应字符串标号->行
                for (int k = 0; k < n; k++)
                {
                    if (!pos.count({table[k][i], table[k][j]}))
                        pos[{table[k][i], table[k][j]}] = k;
                    else
                    {
                        printf("NO\n%d %d\n%d %d\n", pos[{table[k][i], table[k][j]}] + 1, k + 1, i + 1, j + 1);
                        isPNF = false;
                        goto end;
                    }
                }
            }
        }
    end:
        if (isPNF) printf("YES\n");
    }
    return 0;
}