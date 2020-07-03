#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int len;
    scanf("%d", &len);
    string str1, str2;
    cin >> str1 >> str2;
    int move = 0;
    len--; //skip'\0'
    for (int i = 0; i < len / 2; i++)
    {
        char a1, a2, b1, b2;
        a1 = str1[i];
        a2 = str1[len - i];
        b1 = str2[i];
        b2 = str2[len - i];
        set<char> s;
        s.insert(a1);
        s.insert(a2);
        s.insert(b1);
        s.insert(b2);
        int num = s.size();
        if (num == 4)
            move += 2; //四个都不一样
        else if (num == 3)
        { //两个不一样
            if (a1 == a2 || b1 == b2)
                move += 2;
            else
                move++;
        }
        else if (num == 2)
        { //一个和别的不一样
            int i = 0;
            if (a1 == a2)
                i++;
            if (a1 == b1)
                i++;
            if (a1 == b2)
                i++;
            if (i == 2)
                move++;
        }
    }
    if (len % 2 == 0)
        if (str1[len / 2] != str2[len / 2])
            move++;

    cout << move;
    return 0;
}