#include <iostream>

long long chair[5001];

int main()
{
	int N;
	long long int leftN;
	int i, j;
	long long int phase;
	long long int kill_point;
	long long int start_index = 0;
	long long int move = 0;

	scanf("%d", &N);
	leftN = N;

	for (i = 0; i < N; i++)
		chair[i] = i + 1;

	for (phase = 1; phase < N; phase++)
	{
		kill_point = phase * phase*phase;

		if (kill_point <= leftN) {	//한바퀴 내에서 끝나는 경우
			for (i = 0; i < N; i++) {
				if (chair[i] == kill_point) {
					chair[i] = 0;
					leftN -= 1;
					start_index = i + 1;
					break;
				}
			}
		}

		else
		{
			for (i = 0; i < N; i++) {
				if (chair[i] == leftN)
					break;
			}
			move = (kill_point%leftN);	//몇칸 움직여야 하는지 알아낸다.

			for (j = 0; j < move; j++)
			{
				i = i + 1;
				if (chair[i] == 0)
				{
					while (chair[i] == 0)
					{
						if (i >= N) {
							i = 0;
						}
						else
							i++;
					}
				}
			}
			chair[i] = 0;
			leftN -= 1;
			start_index = i + 1;
		}


		for (i = 0; i < leftN; i++, start_index++)	//사람한명 탈락후 순서 초기화
		{
			while (chair[start_index] == 0) {	//시작점에 사람이 없다면
				start_index += 1;
				if (start_index >= N)
					start_index = 0;
			}
			chair[start_index] = i + 1;	//해당 사람에게 숫자 부여
		}

	}

	for (i = 0; i < N; i++)
		if (chair[i] > 0)
			printf("%d\n", i + 1);
	return 0;
}