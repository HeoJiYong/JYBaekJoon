#include <iostream>
#include <cstdio>
using namespace std;
#define SIZE 100
int main()
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = i + i + 1;
	}


	for (int j : arr)
	{
		printf("value : %d \n",j);
	}
	return 0;
}