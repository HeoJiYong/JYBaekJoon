//2178 �̷�ã��
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int mx[] = { -1,0,1,0 };
int my[] = { 0,1,0,-1 };
int map[101][101];

struct node {
	int x = 0;
	int y = 0;
	int count = 1;
};

int N, M;
queue <node> q;

bool is_safe(int x, int y) {
	return ((x >= 0) && (y >= 0) && (x < N) && (y < M));
}

int bfs() {
	int qsize = 0;
	int x, y, count = 1;
	map[0][0] = 0;
	while (!q.empty())
	{
		qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			if ((q.front().x == N - 1) && (q.front().y == M - 1)) {
				cout << q.front().count;
				return 0;
			}
			//ť �Ǿ� ��� ��������
			//4���� �˻� (1. �������� 2.'1'���� 3.�湮���� �ִ���)
			count = q.front().count;
			for (int j = 0; j < 4; j++)
			{
				x = q.front().x + mx[j];
				y = q.front().y + my[j];
				if (is_safe(x, y))
				{
					if (map[x][y] == 1)
					{
						//�� �˻� �� ����ϸ� �ش� ��� ť�� ����.
						//(���Խ� x,y������ + ť�� �Ǿճ���� count+1�� ��)
						q.push({ x ,y ,count + 1 });
						map[x][y] = 0;
					}
				}
			}
			q.pop();
		}
	}
	return 0;
}

int main()
{
	string temp;
	q.push({});
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		temp = "";
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = temp[j] - '0';
		}
	}
	bfs();
}