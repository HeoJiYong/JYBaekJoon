/*
	���� 2212
	�׸���
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
	for (int i = 0; i < sensor; i++)	//������ǥ �Է�
	{
		cin >> xy[i];
	}
	sort(xy, xy + sensor);					//��ǥ����

	for (int i = 0; i < sensor - 1; i++)	//���������� ����
	{
		length[i] = xy[i + 1] - xy[i];
	}
	sort(length, length + (sensor - 1));		//���� ����

	for (int i = 0; i < sensor - center; i++)	//���̰� ū���� ���߱� ������ŭ �����ϰ� ��ħ
	{
		sum += length[i];
	}
	cout << sum;

	return 0;
}