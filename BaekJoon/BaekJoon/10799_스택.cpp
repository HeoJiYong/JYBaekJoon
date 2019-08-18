/*
	백준 10799 스택
	쇠막대문제
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack <char> st;
string str;
int main()
{
	//freopen("input.txt", "r", stdin);
	int stick = 0, result = 0;
	int temp = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push(str[i]);
			stick++;
		}
		else if (str[i] == ')') {
			stick--;
			if (st.top() == '(') {
				st.push(str[i]);
				result = result + stick + temp;
				temp = 0;
			}
			else if (st.top() == ')') {
				st.push(str[i]);
				temp++;
			}
		}
	}
	result += temp;
	cout << result;
	return 0;
}