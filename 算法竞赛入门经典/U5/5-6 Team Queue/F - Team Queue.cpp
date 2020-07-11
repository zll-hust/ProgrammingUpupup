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

queue<int> q;
queue<string> ques[1005];
unordered_map<string, int> team;

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n, kase = 1;
    while (cin >> n && n){
        printf("Scenario #%d", kase++);
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            for(int j = 0; j < m; j++){
                string id;
                cin >> id;
                team[id] = i;
            }
        }
        while(true){
            string order;
            cin >> order;
            if(order[0] == 'S')
                break;
            else if(order[0] == 'E')
            {
                string id;
                cin >> id;
                int t = team[id];
                if(ques[t].empty())
                    q.push(t);
                ques[t].push(id);
            }
            else if(order[0] == 'D')
            {
                int t = q.front();
                cout << ques[t].front() << endl;
                ques[t].pop();
                if(ques[t].empty())
                    q.pop();
            }
        }
        cout << endl;
    }


    return 0;
}