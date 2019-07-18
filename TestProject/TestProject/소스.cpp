#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque <pair<int,int>> mq;
deque <pair<int,int>> tq;

int init_q()
{
	while(!tq.empty()){
		mq.push_back(tq.front());
		tq.pop_front();
	}
	return 0;
}
int main()
{
	//freopen("input.txt","r",stdin);
	int N;
	int move;
	pair<int, int>temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp.second;
		temp.first = i + 1;
		mq.push_back(temp);
	}

	while (!mq.empty()){
		cout << mq.front().first;
		move = abs(mq.front().second) % mq.size()-1;
		if ((mq.front().second) < 0)	move = mq.size()-1 - move;
		mq.pop_front();
		if (mq.empty())
			break;
		for (int i = 0; i < move; i++){
			tq.push_back(mq.front());
			mq.pop_front();
		}
		init_q();
	}
	return 0;
}