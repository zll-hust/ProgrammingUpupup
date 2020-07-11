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

typedef set<int> Set;  // 题目要求的集合
map<Set, int> IDcache; // ID映射到集合
vector<Set> Setcache;  // 根据ID提取集合
stack<int> s;          // 题目中的栈，放置集合的ID

int ID(Set x)
{
    if (IDcache.count(x)) // 若集合已存在
        return IDcache[x];
    Setcache.push_back(x); // 添加新集合
    return IDcache[x] = Setcache.size() - 1;
}

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        while (m--)
        {
            string opr;
            cin >> opr;
            if (opr[0] == 'P')
                s.push(ID(Set()));
            else if (opr[0] == 'D')
                s.push(s.top());
            else
            {
                Set x1 = Setcache[s.top()];
                s.pop();
                Set x2 = Setcache[s.top()];
                s.pop();
                Set x;
                if (opr[0] == 'U')
                    set_union(ALL(x1), ALL(x2), INS(x));
                else if (opr[0] == 'I')
                    set_intersection(ALL(x1), ALL(x2), INS(x));
                else if (opr[0] == 'A')
                {
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }

    return 0;
}