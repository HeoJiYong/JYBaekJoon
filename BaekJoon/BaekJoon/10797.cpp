#include <iostream>
#define NUM 5

using namespace std;

int main()
{
	int date;
	int car;
	int count = 0;
	scanf("%d", &date);
	for (int i = 0; i < NUM; i++)
	{
		scanf(" %d", &car);
		if (car == date)
			count += 1;
	}
	printf("%d\n", count);


}