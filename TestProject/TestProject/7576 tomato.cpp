//���� 5427�� Ʋ��, ���߿� ����. 
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
struct DOT {
	int x = 0;
	int y = 0;
	int count = 0;
};

DOT man;
DOT fire;
queue <DOT> fireq;
int tc;
int w, h;
int mx[4] = { 0, 1, 0, -1 }, my[4] = { -1, 0, 1, 0 };
char map[1001][1001];
bool is_visit[1001][1001] = { false, };
int fire_map[1001][1001] = { 0, };

// # ��, . �����, @ ��, * �����

//������ �� �ִ� ��������
bool is_in_map(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < w) && (y < h);
}

//���� �� �Լ�
int get_fire_map() {

	while (!fireq.empty())
	{
		DOT cur = fireq.front();
		is_visit[cur.y][cur.x] = true;

		int nc = cur.count + 1;

		for (int j = 0; j < 4; j++) //y
		{
			int nx = cur.x + mx[j];
			int ny = cur.y + my[j];
			if (is_in_map(nx, ny))
			{
				if (!is_visit[ny][nx])
				{
					if (map[ny][nx] != '#')
					{
						fireq.push({ nx,ny,nc });
						fire_map[ny][nx] = nc;
						is_visit[ny][nx] = true;
					}
				}
			}
		}

		fireq.pop();
	}

	//���� �� Ȯ�ο� �ڵ�
	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << fire_map[i][j];
		}
		cout << endl;
	}
	cout << "------------------\n";*/

	//Ž������
	//������ �� �ִ� ����
	//. ����
	// - ����ĭ �� > ����ĭ ����� ��
	//	�ʿ� ����
	return 0;
}


//��� �̵� �Լ�
int move_human()
{
	int min_count = 1000000;
	for (int i = 0; i < 1001; i++){
		memset(is_visit[i],false,1001);
	}

	//Ż���� �����ϴٸ� �ּ� �̵����� 1, ���� 0= Ż�� �Ұ���
	queue <DOT> hq;
	hq.push(man);
	while (!hq.empty())
	{
		DOT cur = hq.front();
		int nc = cur.count + 1;
		is_visit[cur.y][cur.x] = true;

		for (int j = 0; j < 4; j++)
		{
			int nx = cur.x + mx[j];
			int ny = cur.y + my[j];

			if (is_in_map(nx, ny))
			{
				if (!is_visit[ny][nx])
				{
					if (nc < fire_map[ny][nx])
					{
						hq.push({ nx, ny,nc });
						is_visit[ny][nx] = true;
					}
				}
			}
			//�� ���̶�� Ȥ�� Ż������ Ȯ���Ѵ�.
			else
			{
				min_count = (min_count) > nc ? nc : min_count;
			}
		}
		hq.pop();
	}
	return min_count == 1000000 ? 0 : min_count;
}

int main()
{
	cin >> tc;
	char temp;
	for (int i = 0; i < tc; i++)
	{
		cin >> w >> h;
		for (int t = 0; t < 1001; t++)
		{
			memset(is_visit[t],false,1001);
			memset(fire_map[t], 0, 1001);
		}
		//�� �ʱ�ȭ
		for (int hi = 0; hi < h; hi++)
		{
			for (int wi = 0; wi < w; wi++)
			{
				cin >> temp;
				//�� �޾Ҵٸ� ť�� ���� ���߿� Ž���ϵ��� �����.
				if (temp == '*')
				{
					fireq.push({ wi,hi,0 });
					fire_map[hi][wi] = 1;
				}
				else if (temp == '@')
				{
					man.x = wi;
					man.y = hi;
					man.count = 0;
				}
				map[hi][wi] = temp;
			}
		}
		get_fire_map();
		if (int result = move_human())
		{
			cout << result<<"\n";
		}
		else
		{
			cout << "IMPOSSIBLE\n";
		}
		//���� �� ����� ���� bfs -�� �Ҿ��ϳ������� �湮 ť �ϳ��� ������.
		//�Ҿ��� �ΰ� �̻��� ���, (���Ǹ� ���� > ���� �Ҿ�����) �϶����� �湮
		//���ڰ� ���� ���� �ʿ��� ����� �̵�bfs (���� �̵��� < ���� ����) �϶����� �湮
		//if ���bfs ��������� ����ȯ
	}
	return 0;
}