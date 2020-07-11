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

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

map<string, int> table;
vector<pair<string, string> > words;

string standlize(const string &s)
{
    string ans = s;
    for (int i = 0; i < ans.length(); i++)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(), ans.end()); // 之前没注意string是vector
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    string str;
    while (cin >> str && str != "#")
    {
        string word = standlize(str);
        words.push_back(make_pair(str, word));
        if(!table.count(word)) table[word] = 0;
        table[word]++;
    }
    vector<string>ans;
    for(int i = 0; i < words.size(); i++){
        if(table[words[i].second] == 1)
            ans.push_back(words[i].first);
    }
    sort(ans.begin(), ans.end());
    for (auto word : ans)
        cout << word << endl;
    return 0;
}