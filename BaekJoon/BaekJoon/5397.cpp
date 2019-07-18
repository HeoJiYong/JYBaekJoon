#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque <int> dq1;
deque <int> dq2;

int main()
{
	freopen("input.txt", "r", stdin);
	int N;
	int temp;
	int index = 1;
	int move = 0;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> temp, dq1.push_back(temp);

	while (!dq2.empty())
	{
		move = 0;
		if (abs(dq1.front() >= dq1.size()))
			move = dq1.front() % dq1.size();
		else
			move = dq1.front();

		if (dq1.front() < 0)	//move left
		{
			for (int i = 0; i < move; i++)
			{
				dq2.push_front(dq1.);
			}
		}
		else if (dq1.front() > 0)	//move right
		{
			for (int i = 0; i < move; i++)
			{
				dq2.push_back(dq1.front());
				dq1.pop_front();
			}
			dq1.pop_front();
		}
		while (!dq2.empty())	//다시 dq1 을 제자리로
		{
			dq1.push_back(dq2.front());
			dq2.pop_front();
		}
	}

	return 0;
}