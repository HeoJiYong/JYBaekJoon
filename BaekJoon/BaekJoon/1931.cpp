/*
백준 1971 그리디 알고리즘
*/

#include <iostream>
#include <algorithm>
#define START second
#define END first
using namespace std;

pair <int, int > meeting[100000];

int main()
{
	//freopen("input.txt","r",stdin);
	int tc;
	int mc = 0; // meeting count

	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> meeting[i].START;
		cin >> meeting[i].END;
	}
	sort(meeting, meeting + tc);
	int endtime = 0;

	for (int i = 0; i < tc; i++)
	{
		if (endtime <= meeting[i].START)
		{
			mc++;
			endtime = meeting[i].END;
		}
	}
	cout << mc;
	return 0;
}