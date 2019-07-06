#include <iostream>
#include <queue>

using namespace std;
vector <int> v;

int main()
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		v.push_back(i + 1);
	}

	for (int i = 0; i < num; i++) {
		if (i % 2 == 1) {
			v.push_back(v[i]);
			num += 1;
		}
		else
			printf("%d ", v[i]);
	}

}