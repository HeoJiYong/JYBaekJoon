#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[9];
	int cut = 0;
	int sum = 0;
	int index1 = 0, index2 = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
		sum = sum + a[i];
	}

	cut = sum - 100;

	sort(a, a + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if ((a[i] + a[j]) == cut && (a[i] != a[j])) {
				index1 = i;
				index2 = j;
				goto NEXT;
			}
		}
	}
NEXT:

	for (int i = 0; i < 9; i++)
		if (index1 != i && index2 != i)
			printf("%d\n", a[i]);
	return 0;
}