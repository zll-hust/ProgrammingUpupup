#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//#define LOCAL

struct Student
{
	string id;
	int score;

	Student()
	{
		score = 0;
	}
};

bool comp(Student x, Student y)
{
	if (x.score != y.score)
		return x.score > y.score;
	else
		return x.id < y.id;
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int stdNr = 0, titNr, passScore;
	while (scanf("%d %d %d", &stdNr, &titNr, &passScore))
	{
		if (stdNr == 0) break;
		int* titScore = new int[titNr + 5];
		Student* students = new Student[stdNr + 5];

		for (int i = 0; i < stdNr; i++)
			students[i] = Student();

		for (int i = 0; i < titNr; i++)
			scanf("%d", titScore + i);

		for (int i = 0; i < stdNr; i++)
		{
			string stdId;
			int stdTitNr;
			cin >> stdId >> stdTitNr;
			students[i].id = stdId;
			for (int j = 0; j < stdTitNr; j++)
			{
				int ts;
				scanf("%d", &ts);
				students[i].score += titScore[ts - 1];
			}
		}

		sort(students, students + stdNr, comp);

		int passId = 0;
		for (passId = 0; passId < stdNr; passId++)
			if (students[passId].score < passScore)
				break;

		printf("%d\n", passId);
		for (int i = 0; i < passId; i++)
			cout << students[i].id << " " << students[i].score << endl;
	}

	return 0;
}