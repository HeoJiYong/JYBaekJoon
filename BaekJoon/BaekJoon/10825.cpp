#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define NAME first.first
#define KOR first.second
#define ENG second.first
#define MATH second.second

using namespace std;

typedef pair<string, int> p1;
typedef pair<int, int>p2;

bool Cmp(pair<p1, p2> a, pair<p1, p2>b)
{
	if (a.KOR == b.KOR)
	{
		if (a.ENG == b.ENG)
		{
			if (a.MATH == b.MATH)
			{
				return a.NAME.compare(b.NAME) < 0;
			}
			return a.MATH > b.MATH;
		}
		return a.ENG < b.ENG;
	}
	return a.KOR > b.KOR;
}
int main()
{
	int num, i;
	scanf("%d", &num);	//학생수 입력

	vector <pair<p1, p2>> v(num);
	for (i = 0; i < num; i++)	//학생수만큼
	{
		cin >> v[i].NAME;
		scanf("%d %d %d", &v[i].KOR, &v[i].ENG, &v[i].MATH);
	}

	sort(v.begin(), v.end(), Cmp);

	for (i = 0; i < num; i++)
	{
		cout << v[i].NAME << "\n";
	}
	return 0;
}
