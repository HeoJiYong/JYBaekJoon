#include <iostream>
#include <string.h>

using namespace std;
char dish[51];

int main()
{
	int h = 0;
	scanf("%s", dish);
	if (strlen(dish) >= 3 && strlen(dish) <= 50)
	{
		h += 10;
		for (int i = 1; i < strlen(dish); i++)
		{
			if (dish[i] == '(')
			{
				switch (dish[i - 1])
				{
				case '(': h += 5;
					break;
				case ')': h += 10;
					break;
				}
			}
			else if (dish[i] == ')')
			{
				switch (dish[i - 1])
				{
				case '(':h += 10;
					break;
				case ')': h += 5;
					break;
				}
			}
		}
		printf("%d\n", h);
	}
	return 0;
}