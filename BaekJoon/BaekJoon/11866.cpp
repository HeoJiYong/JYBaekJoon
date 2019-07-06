#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int N, M;
	int cur = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	if (1 <= M && M <= N && N <= 1000)	//조세퍼스 조건
	{
		for (int i = 0; i < N; i++)
			v.push_back(i + 1);

		printf("<");		// '<' 로시작
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 1; j++) {
				cur++;
				v.push_back(v[cur - 1]);
			}
			printf("%d, ", v[cur]);
			cur++;
		}

		for (int j = 0; j < M - 1; j++) {
			cur++;
			v.push_back(v[cur - 1]);
		}
		printf("%d>\n", v[cur]);
	}
	return 0;
}