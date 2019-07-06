#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
queue <int> q;
char com[10];

int main()
{
	int num, a;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		scanf(" %s", com);
		if (strcmp(com, "push") == 0) {
			scanf(" %d", &a);
			q.push(a);
		}
		if (strcmp(com, "pop") == 0)
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		if (strcmp(com, "size") == 0)
			cout << q.size() << endl;

		if (strcmp(com, "empty") == 0)
			printf("%d\n", q.empty());

		if (strcmp(com, "front") == 0) {
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		if (strcmp(com, "back") == 0) {
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.back());
		}
	}
	return 0;
}