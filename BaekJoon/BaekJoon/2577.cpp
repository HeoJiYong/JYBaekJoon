#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int check[10] = { 0, };
int main()
{
	int Num;
	int result = 1;
	double temp = 0;
	for (int i = 0; i < 3; i++) {
		scanf(" %d", &Num);
		result *= Num;
	}

	while (result > 0)
	{
		temp = result % 10;
		result = result / 10;
		check[(int)temp] += 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", check[i]);
	}
	return 0;
}