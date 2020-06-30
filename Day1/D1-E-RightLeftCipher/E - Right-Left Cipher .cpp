#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    string incode, decode;
    cin >> incode;
    int len = incode.length();


    // int x = 0, y = len - 1;
    // for (int i = len - 1; i >= 0; i--)
    // {
    //     if (i % 2 == 0)
    //         decode = incode[x++] + decode;
    //     else
    //         decode = incode[y--] + decode;
    // }

    int mid = (len + 1) / 2 - 1;
    decode += incode[mid];
    for(int i = 1; i < len; i++){
        decode += incode[mid + i];
        decode += incode[mid - i];
    }


    cout << decode << endl;

    return 0;
}