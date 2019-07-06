#include <iostream>
using namespace std;
int yut[4];
char result[3];
int main()
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 4; j++) {
			scanf(" %d", &yut[i]);
			sum += yut[i];
		}
		switch (sum)
		{
		case 0: result[i] = 'D';
			break;
		case 1: result[i] = 'C';
			break;
		case 2: result[i] = 'B';
			break;
		case 3: result[i] = 'A';
			break;
		case 4: result[i] = 'E';
			break;
		}
	}
	for (int i = 0; i < 3; i++)
		printf("%c\n", result[i]);
	return 0;
}