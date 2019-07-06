#include <iostream>

int L = 1, P = 1, V = 1, day, temp;
int main()
{
	for (int i = 0;; i++) {
		scanf("%d %d %d", &L, &P, &V);
		if (!L && !P && !V) return 0;
		temp = (V%P) > L ? L : (V%P);
		day = (L*(V / P)) + temp;
		printf("Case %d: %d\n", i + 1, day);
	}
	return 0;
}