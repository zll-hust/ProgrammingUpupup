#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

// #define LOCAL

unsigned x, y, z;

unsigned rng61()
{
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int peoNr, titNr, kase = 0;
    while (cin >> peoNr >> titNr >> x >> y >> z)
    {
        vector<pair<int, int>> b;
        for (int i = 0; i < titNr; i++)
        {
            int temp;
            cin >> temp;
            b.push_back(make_pair(temp, i));
        }

        unsigned *rating = new unsigned[peoNr + 5];
        for (int i = 0; i < peoNr; i++)
            rating[i] = rng61();

        // sort(b.begin(), b.end());
        b.push_back(make_pair(peoNr, titNr));

        unsigned *ans = new unsigned[titNr + 5];
        for (int i = titNr - 1; i >= 0; i--)
        {
            nth_element(rating, rating + b[i].first, rating + b[i + 1].first);
            ans[b[i].second] = rating[b[i].first];
        }

        kase++;
        cout << "Case #" << kase << ":";
        for (int i = 0; i < titNr; i++)
            cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}