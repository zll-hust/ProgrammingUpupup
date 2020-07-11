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
#include <list>
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

int nex[100005];
int last, current;

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    string text;
    while (cin >> text)
    {
        text = " " + text;
        int n = text.size() - 1;
        last = current = 0;
        nex[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            char ch = text[i];
            if (ch == '[')
                current = 0;
            else if (ch == ']')
                current = last;
            else
            {
                nex[i] = nex[current];
                nex[current] = i;
                if (current == last)
                    last = i;
                current = i;
            }
            // for (int i = 0; i <= n; i++)
                // cout << nex[i];
            // cout << endl;
        }
        for (int i = nex[0]; i != 0; i = nex[i])
            printf("%c", text[i]);
        printf("\n");
    }

    return 0;
}

// string s;
// int main() {
//     while (cin >>s) {
//         list<char> l;
//         auto p = l.begin(); // 初始化
//         for (auto ch : s) {
//             if (ch == '[') p = l.begin(); // 开头
//             else if (ch == ']') p = l.end(); // 结尾
//             else {
//                 p = l.insert(p, ch); // 返回插入数据的迭代器
//                 p ++; // 后移一位
//             }
//         }
//         for (auto ch : l) cout <<ch; // 输出
//         puts("");
//     }
//     return 0;
// }