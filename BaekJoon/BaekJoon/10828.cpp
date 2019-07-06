#include <iostream>
#include <cstdio>
#include <stack>
//#include <deque>
//#include <queue>
//#include <functional> // less, greater ÇÔ¼ö
#include <string.h>
#include <vector>
using namespace std;
stack <int> st;
char com[10];

int main()
{
	int a;
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf(" %s", com);
		if (strcmp(com, "push") == 0) {
			scanf("%d", &a);
			st.push(a);
		}
		if (strcmp(com, "pop") == 0)
		{
			if (st.empty() == 1)
				printf("-1\n");
			else
			{
				printf("%d\n", st.top());
				st.pop();
			}
		}
		if (strcmp(com, "size") == 0)
			cout << st.size() << "\n";
		if (strcmp(com, "empty") == 0)
			printf("%d\n", st.empty());
		if (strcmp(com, "top") == 0)
		{
			if (st.empty() == 1)
				printf("-1\n");
			else
				printf("%d\n", st.top());
		}
	}
	return 0;
}