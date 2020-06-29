#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// #define LOCAL

bool comp(pair<string, int>p1, pair<string, int>p2)
{
    return p1.second > p2.second;
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int caseNr;
    scanf("%d", &caseNr);
    
	for(int i = 0; i < caseNr; i++)
	{
		int peopleNr;
        scanf("%d", &peopleNr);
        cin.get();
        pair<string, int> people[105];

		for (int j = 0; j < peopleNr; j++)
		{
            string name;
            int birthday = 0;
            string data;
            getline(cin, data);
            name = data.substr(0, data.length() - 5);
            for(int k = data.length() - 4; k < data.length() - 1; k++)
            {
                birthday += data[k] - '0';
                birthday *= 10;
            }
            birthday += data[data.length() - 1] - '0';
            
			people[j] = make_pair(name, birthday);
		}

		sort(people, people + peopleNr, comp);

		for (int j = 0; j < peopleNr; j++)
			cout << people[j].first << endl;
	}

	return 0;
}