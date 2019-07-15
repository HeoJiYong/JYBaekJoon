/*
	백준 13904
	그리디
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define DEADLINE second
#define SCORE first

pair<int, int> homework[1000];

bool option(pair<int, int> a, pair<int, int> b)
{
	return a > b;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int num, index=0;
	int sum = 0;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> homework[i].DEADLINE;
		cin >> homework[i].SCORE;
	}
	sort(homework, homework + num);
	sum = sum + homework[0].SCORE;
	index = homework[0].DEADLINE;

	for (int i = 0; i < num; i++)
	{
		if (index != homework[i].DEADLINE)
		{
			sum += homework[i].SCORE;
			index = homework[i].DEADLINE;
		}
	}

	cout << sum<<endl;
	for (int i = 0; i < num; i++)
	{
		cout << homework[i].DEADLINE << " ";
		cout << homework[i].SCORE << endl;
	}
}