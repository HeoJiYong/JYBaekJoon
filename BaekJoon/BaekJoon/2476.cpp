#include <iostream>
using namespace std;

int main()
{
	int maxMoney = 0;
	int Money = 0;
	int num;
	int dice[3];
	int j;
	scanf("%d", &num);
	if (num >= 2 && num <= 1000)
	{
		for (j = 0; j < num; j++)
		{
			Money = 0;
			for (int i = 0; i < 3; i++)
			{
				scanf(" %d", &dice[i]);
			}

			if (dice[0] == dice[1] && dice[1] == dice[2])	//다같으면
			{
				Money = 10000 + (dice[0] * 1000);
			}
			else if (dice[0] == dice[1] || dice[1] == dice[2] || dice[2] == dice[0])
			{
				if (dice[0] == dice[1])
				{
					Money = 1000 + (dice[0] * 100);
				}
				else if (dice[1] == dice[2])
				{
					Money = 1000 + (dice[1] * 100);
				}
				else if (dice[2] == dice[0])
				{
					Money = 1000 + (dice[2] * 100);
				}
			}
			else
			{
				int maxNum = 0;
				for (int i = 0; i < 3; i++) {
					if (maxNum < dice[i]) {
						maxNum = dice[i];
					}
				}
				Money = 100 * maxNum;
			}
			if (maxMoney < Money) {
				maxMoney = Money;
			}
		}
		printf("%d\n", maxMoney);
	}

	return 0;
}