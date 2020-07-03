#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

#define LOCAL

string getNoSpaceStr(string str)
{
    string s = str;
    for (string::iterator it = s.begin(); it != s.end(); it++)
    {
        if (*it == ' ' || *it == '\n' || *it == '\t')
        {
            s.erase(it);
            it--;
        }
    }

    return s;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int kase;
    scanf("%d", &kase);
    cin.get();
    while (kase-- > 0)
    {
        string start, end, real_ans;
        getline(cin, start);
        getline(cin, real_ans);
        getline(cin, end);
        while (end != "END")
        {
            real_ans += end + '\n';
            getline(cin, end);
        }

        string start2, end2, user_ans;
        getline(cin, start2);
        getline(cin, user_ans);
        getline(cin, end2);
        while (end2 != "END")
        {
            user_ans += end2 + '\n';
            getline(cin, end2);
        }

        string real_ans2 = getNoSpaceStr(real_ans);
        string user_ans2 = getNoSpaceStr(user_ans);
        if (real_ans == user_ans)
        {
            cout << "Accept" << endl;
        }
        else
        {
            if (real_ans2 == user_ans2)
                cout << "Presentation Error" << endl;
            else
                cout << "Wrong Answer" << endl;
        }
    }
    return 0;
}