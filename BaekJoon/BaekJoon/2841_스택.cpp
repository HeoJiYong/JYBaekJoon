//2841 ���� �ܰ��α�Ÿ
#include<iostream>
#include<stack>
using namespace std;
stack <int> st[6];
int MoveCnt;
int main()
{
	int N, P, Stemp, Ptemp;
	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		cin >> Stemp >> Ptemp;	//��(Stemp), ����(Ptemp) �Է�
		Stemp -= 1;

		while (!st[Stemp].empty()) {	//�ٿ� �հ����� �� ��� �ȵ�.
			if (st[Stemp].top() <= Ptemp) {				//¤�� ������ �� Ŭ��
				if (st[Stemp].top() == Ptemp)	break;	//But ¤�� ���� = ¤�� ���� �̸� �׳� ����
				st[Stemp].push(Ptemp);	//�� ��´�.
				MoveCnt++;				//������ +1
				break;
			}
			else if (st[Stemp].top() > Ptemp) {	//¤�� ������ �� �۴ٸ�
				st[Stemp].pop();	//¤���ִ� �� ����.
				MoveCnt++;			//������ +1
			}
		}
		//�ش� �ٿ� �հ����� ���ٸ� ¤�´�.
		if (st[Stemp].empty()) {
			st[Stemp].push(Ptemp);
			MoveCnt++;
		}
	}
	cout << MoveCnt << "\n";
	return 0;
}