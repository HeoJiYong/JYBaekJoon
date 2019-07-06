#include <iostream>

int N, K, temp, i, sum = 0;
int Money[10] = { 0, };

int main()
{
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%d", &Money[i]);
	}

	for (i = N - 1; i >= 0; i--) {
		if (K >= Money[i]) {	//금액이 더 크면
			temp = (K / Money[i]);	//금액/50000 한 몫은 50000원권의 갯수
			sum = sum + temp;	//갯수를 저장
			K = K % Money[i];
		}
	}
	printf("%d\n", sum);
	return 0;
}