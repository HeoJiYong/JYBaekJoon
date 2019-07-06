#include <iostream>
#include <stack>

using namespace std;

stack <int> s;
char ch[200000];

int main()
{
	int n, num, ch_index = 0;
	int Put_Num = 1;
	int num_count = 0;

	//freopen("Text.txt", "r", stdin);
	scanf("%d", &n);	//정수값받고

	while (1)
	{
		scanf("%d", &num);
		num_count++;
		if (s.empty())	//비었을때
		{
			while (1) {
				s.push(Put_Num);
				ch[ch_index] = '+';
				ch_index++;
				Put_Num++;
				if (s.top() == num)
					break;
			}
		}
		else if (s.top() < num)
		{
			while (1) {
				s.push(Put_Num);
				ch[ch_index] = '+';
				ch_index++;
				Put_Num++;
				if (s.top() == num)
					break;
			}
		}
		if (s.top() > num)
		{
			printf("NO\n");
			return 0;
		}
		else if (s.top() == num)
		{
			s.pop();
			ch[ch_index] = '-';
			ch_index++;
		}
		if (s.empty() && num_count == n)
			break;
	}

	for (int i = 0; i < ch_index; i++)
		printf("%c\n", ch[i]);

	return 0;
}