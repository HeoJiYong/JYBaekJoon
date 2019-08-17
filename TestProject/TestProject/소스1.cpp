/*
	���� 2493 ���ù���
	�迭 > �޸� �ʰ�
	���� > �ð��ʰ�
	cin ��� scanf ���� �ð��ʰ� �ذ�.
*/
#include <iostream>
#include <stack>
using namespace std;

stack <pair<int, int>>st;

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	//cin >> N;
	scanf("%d",&N);
	pair <int, int> temp;
	for (int i = 0; i < N; i++) {
		//cin >> temp.first;
		scanf("%d", &temp.first);
		temp.second = i + 1;

		//���� ������ ���� ������ ��Ÿ�� ����(st�� ��������� �𸣰� st.top�� �����Ϸ� �ؼ�.)
		while ((!st.empty())&& (st.top().first < temp.first)) {
			st.pop();
		}
		if (st.empty()) {
			cout << "0 ";
		}
		else {
			cout << st.top().second << " ";
		}
		st.push(temp);
	}

	return 0;
}