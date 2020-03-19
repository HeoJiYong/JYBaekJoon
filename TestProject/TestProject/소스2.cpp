#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	/*
	int temp = 0b0001;	//2진수로 넣기
	printf("%");
	*/
	/*
	int n = 10;
	int a = 9;
	for (int i = n; i >= 0; i--){
		printf("%d",(a>>i)&1);
	}
	return 0;
	*/ 
	long long int N, K;
	cin >> N >> K;
	long long int flag = N / 2;
	long long int pattern1 = 1, pattern2 = 1;
	if (N % 2 == 0) {
		for (long long int i = 0; i < flag - 1; i++) {
			pattern1 = (pattern1 * 2) + 1;
			pattern2 = (pattern2 * 4) + 1;
		}
		if (K >= pattern1)	K++;
		if (K >= pattern2)	K++;
	}
	if (K >= pow(2, N)) {
		cout << "-1";
		return 0;
	}
	for (long long int i = N - 1; i >= 0; i--) {
		if (((K >> i) & 1))
			cout << ")";
		else
			cout << "(";
	}
	return 0;
}