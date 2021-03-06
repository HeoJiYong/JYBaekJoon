/*
	백준 2212
	그리디
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int sensor, center;
	int xy[10000];
	int length[10000];
	int sum = 0;

	cin >> sensor >> center;
	for (int i = 0; i < sensor; i++)	//센서좌표 입력
	{
		cin >> xy[i];
	}
	sort(xy, xy + sensor);					//좌표정렬

	for (int i = 0; i < sensor - 1; i++)	//센서끼리의 거리
	{
		length[i] = xy[i + 1] - xy[i];
	}
	sort(length, length + (sensor - 1));		//거리 정렬

	for (int i = 0; i < sensor - center; i++)	//집중국 갯수만큼 빼고 거리합 구함
	{
		sum += length[i];
	}
	cout << sum;

	return 0;
}