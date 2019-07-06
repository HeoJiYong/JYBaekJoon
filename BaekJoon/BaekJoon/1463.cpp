#include <cstdio>
#include <algorithm>
#define MAX 1000005
using namespace std;
int dp[MAX], n;

int func(int n)
{
	if (n == 1)
		return 0;
	int &ret = dp[n];
	if (ret != -1)
		return ret;
	ret = func(n - 1) + 1;
	if (!(n % 2)) ret = min(func(n / 2) + 1, ret);
	if (!(n % 3)) ret = min(func(n / 3) + 1, ret);
	return ret;
}


int main()
{
	scanf("%d", &n);
	fill(dp, dp + MAX, -1);
	printf("%d\n", func(n));
	return 0;
}