#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack <char> st1, st2;
void move_left()
{
	if (!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}
}
void move_right()
{
	if (!st2.empty()){
		st1.push(st2.top());
		st2.pop();
	}
}
void del()
{
	if (!st1.empty())
		st1.pop();
}
void back_result()
{
	while (!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}
	while (!st2.empty()){
		 cout << st2.top();
		 st2.pop();
	}
	cout << endl;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int tc;
	string temp;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			if (temp[j] == '<')
				move_left();
			else if (temp[j] == '>')
				move_right();
			else if (temp[j] == '-')
				del();
			else {
				st1.push(temp[j]);
			}
		}
		back_result();
	}
	return 0;
}