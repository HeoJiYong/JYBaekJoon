#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define PRIORITY first
#define TARGET second

using namespace std;
queue <pair<int, int>> q;

inline bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int num, target;	//N:문서갯수 , M:몇번째 문서가 궁금한지
	int TestCase, priority;
	int Count = 0, i = 0, j = 0;
	scanf("%d", &TestCase);

	for (i = 0; i < TestCase; i++) {
		scanf("%d %d", &num, &target);	//6  0  ->M+1번의 Pop이 이루어 져야함
		if (!((num > 0 && num <= 100) && (target >= 0 && target < num)))
			return 0;
		vector <int> v;
		for (j = 0; j < num; j++) {
			scanf("%d", &priority);	//우선순위	.vector에 저장
			v.push_back(priority);

			if (j == target)
				q.push(make_pair(priority, 1));
			else
				q.push(make_pair(priority, 0));
		}
		sort(v.begin(), v.end(), cmp);
		Count = 0;
		while (1) {
			if (v[Count] == q.front().PRIORITY) {
				Count += 1;
				if (q.front().TARGET) {
					printf("%d\n", Count);
					break;
				}
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		while (q.size())
			q.pop();
	}
	return 0;
}