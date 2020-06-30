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
        if (str1[0] != str2[0])//特殊判断第一个位置，第一个之前不能添加字符
        {
            printf("No\n");
            continue;
        }
        int k = 0;
        int flag = 1;
        for (int j = 0; j < str1.length(); j++) //跳过第一个字符
        {
            if (k == str2.length())
            {
                flag = 0;
                break;
            }
            while (k < str2.length())
            {
                if (str1[j] == str2[k])
                {
                    k++;
                    break;
                }
                else if (str1[j - 1] == str2[k])
                {
                    k = str2.length(); // 插入的字符不能和前一个一样，一样则退出
                    break;
                }
                else
                    k++;
                if (k == str2.length())
                    flag = 0;
            }
        }

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}