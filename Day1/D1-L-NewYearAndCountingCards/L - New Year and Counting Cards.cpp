#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    string str;
    cin >> str;

    string vowel = "aeiou";
    string odd = "13579";

    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (vowel.find(str[i]) != string::npos)
            sum++;
        else if (odd.find(str[i]) != string::npos)
            sum++;
    }

    cout << sum << endl;

    return 0;
}