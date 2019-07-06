#include <cstdio>

int N, S, a[21], cnt;

void func(int idx, int sum)//몇번째 인덱스(현재 볼 값), 부분집합의 합
{
	if (idx &&sum == S) cnt++;
	if (idx == N)//끝까지 ㄲ갔을때 리ㅓ턴
		return;
	//이전 배열값 볼 필요없음 ,그래서 받아온 idx값을 반복의시작점으로
	for (int i = idx; i < N; i++) {
		func(i + 1, sum + a[i]);
	}
}

int main()
{

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	func(0, 0);//처음 시작위치는 0,0
	printf("%d\n", cnt);
	return 0;
}