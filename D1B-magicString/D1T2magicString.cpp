#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int caseNr;
    scanf("%d", &caseNr);
    for (int i = 0; i < caseNr; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        int conversionNr;
        cin >> conversionNr;
        int table[24][24];
        memset(table, 0, sizeof(table));
        for (int j = 0; j < conversionNr; j++)
        {
            char c1, c2;
            cin >> c1 >> c2;
            table[c1 - 97][c2 - 97] = 1; // c1能转化为c2
        }

        int k = 0;
        int happy = 1;
        for (int j = 0; j < str1.length(); j++)
        {
            if (k == str2.length())
            {
                happy = 0;
                break;
            }
            while (k < str2.length())
            {
                if (str1[j] == str2[k] || table[str2[k] - 97][str1[j] - 97] == 1)
                {
                    k++;
                    break;
                }
                else
                    k++;
                if (k == str2.length())
                {
                    happy = 0;
                    break;
                }
            }
        }

        if (happy)
            printf("Case #%d: happy\n", i + 1);
        else
            printf("Case #%d: unhappy\n", i + 1);
    }

    return 0;
}