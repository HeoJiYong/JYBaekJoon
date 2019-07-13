#include <iostream>
#include <algorithm>

using namespace std;

pair<int , pair<int, int>> meeting[100000];

int main()
{
	freopen("input.txt", "r", stdin);
	int tc;
	int mc = 0; // meeting count
	int temp;

	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> meeting[i].second.first;	//시작시간
		cin >> meeting[i].second.second;		//끝나는 시간
		meeting[i].first = meeting[i].second.second - meeting[i].second.first;
	}
	sort(meeting,meeting+tc);
	for (int i = 0; i < tc; i++)
	{
		cout << meeting[i].second.first << " " << meeting[i].second.second << " " << meeting[i].first << endl;
	}


	return 0;
}