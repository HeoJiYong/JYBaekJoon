/*
	백준 2493 스택문제
	배열 > 메모리 초과
	스택 > 시간초과
	cin 대신 scanf 사용시 시간초과 해결.
*/
#include <iostream>
#include <stack>
using namespace std;

stack <pair<int, int>>st;

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	//cin >> N;
	scanf("%d",&N);
	pair <int, int> temp;
	for (int i = 0; i < N; i++) {
		//cin >> temp.first;
		scanf("%d", &temp.first);
		temp.second = i + 1;

		//뒤쪽 논리식이 먼저 나오면 런타임 에러(st이 비었는지도 모르고 st.top을 참조하려 해서.)
		while ((!st.empty())&& (st.top().first < temp.first)) {
			st.pop();
		}
		if (st.empty()) {
			cout << "0 ";
		}
		else {
			cout << st.top().second << " ";
		}
		st.push(temp);
	}

	return 0;
}