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
#include <unordered_map>
using namespace std;

typedef long long ll;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

set<string>dir;

int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    string words;
    while (cin >> words) {
        for (int i = 0; i < words.length(); i++) {
            if (isalpha(words[i]))
                words[i] = tolower(words[i]);
            else
                words[i] = ' ';
        }
        stringstream ss(words);
        string buf;
        while (ss >> buf)
            dir.insert(buf);
    }
    for (auto word : dir) 
        cout << word << endl;

    return 0;
}