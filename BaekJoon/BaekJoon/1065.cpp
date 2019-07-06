#include <iostream>
using namespace std;
int main()
{
	int Num, cnt = 99;
	scanf("%d", &Num);
	if (Num < 100)
		printf("%d\n", Num);
	else {
		for (int i = 100; i <= Num; i++) {
			int x = i / 100;	//100ÀÇ ÀÚ¸´¼ö
			int y = (i % 100) / 10;	//10ÀÇ ÀÚ¸´¼ö
			int z = i % 10;		//1ÀÇ ÀÚ¸´¼ö
			if ((x - y) == (y - z))
				cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}