#include <utility>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	vector <pair<int, int>> v;
	int num, i;
	scanf("%d", &num);
	v.resize(num);
	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end());
	for (i = 0; i < num; i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}