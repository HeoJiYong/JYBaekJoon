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
	int num, target;	//N:�������� , M:���° ������ �ñ�����
	int TestCase, priority;
	int Count = 0, i = 0, j = 0;
	scanf("%d", &TestCase);

	for (i = 0; i < TestCase; i++) {
		scanf("%d %d", &num, &target);	//6  0  ->M+1���� Pop�� �̷�� ������
		if (!((num > 0 && num <= 100) && (target >= 0 && target < num)))
			return 0;
		vector <int> v;
		for (j = 0; j < num; j++) {
			scanf("%d", &priority);	//�켱����	.vector�� ����
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