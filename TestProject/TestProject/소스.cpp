/*
2493
스택
시간초과
*/
#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> st;
stack<pair<int, int>> stemp;

int retIndex() {
	pair <int, int>p;
	p = st.top();
	st.pop();
	while (!st.empty()) {
		if (p.first < st.top().first) {
			return st.top().second;
		}
		stemp.push(st.top());
		st.pop();
	}
	return 0;
}
int rollBack() {
	while (!stemp.empty()) {
		st.push(stemp.top());
		stemp.pop();
	}
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	pair<int, int> buff;
	stack <int> result;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> buff.first;
		buff.second = i + 1;
		st.push(buff);
	}
	/*검사*/
	while (!st.empty()) {
		result.push(retIndex());
		rollBack();
	}
	while (!result.empty()) {
		cout << result.top()<<" ";
		result.pop();
	}
	return 0;
}