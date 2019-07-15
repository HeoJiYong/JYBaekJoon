/*
	백준 13904
	그리디
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue <int> pq;
pair <int, int> homework[1000];
int n, sum, date;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> homework[i].first >> homework[i].second;
	sort(homework, homework + n);
	for (int i = 0; i < n; i++) {
		if (date == homework[i].first) {
			date--;
			pq.pop();
		}
		pq.push(-homework[i].second);
		date++;
	}
	while (!pq.empty()) {
		sum += (-pq.top());
		pq.pop();
	}
	cout << sum;
	return 0;
}