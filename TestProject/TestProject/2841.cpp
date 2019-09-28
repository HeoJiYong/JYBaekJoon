//2841 스택 외계인기타
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
		cin >> Stemp >> Ptemp;	//줄(Stemp), 프렛(Ptemp) 입력
		Stemp -= 1;

		while (!st[Stemp].empty()) {	//줄에 손가락이 다 비면 안됨.
			if (st[Stemp].top() <= Ptemp) {				//짚을 프렛이 더 클때
				if (st[Stemp].top() == Ptemp)	break;	//But 짚은 프렛 = 짚을 프렛 이면 그냥 나감
				st[Stemp].push(Ptemp);	//손 얹는다.
				MoveCnt++;				//움직임 +1
				break;
			}
			else if (st[Stemp].top() > Ptemp) {	//짚을 프렛이 더 작다면
				st[Stemp].pop();	//짚고있는 손 뗀다.
				MoveCnt++;			//움직임 +1
			}
		}
		//해당 줄에 손가락이 없다면 짚는다.
		if (st[Stemp].empty()) {
			st[Stemp].push(Ptemp);
			MoveCnt++;
		}
	}
	cout << MoveCnt << "\n";
	return 0;
}