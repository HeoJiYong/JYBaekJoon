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
		if (K >= Money[i]) {	//�ݾ��� �� ũ��
			temp = (K / Money[i]);	//�ݾ�/50000 �� ���� 50000������ ����
			sum = sum + temp;	//������ ����
			K = K % Money[i];
		}
	}
	printf("%d\n", sum);
	return 0;
}