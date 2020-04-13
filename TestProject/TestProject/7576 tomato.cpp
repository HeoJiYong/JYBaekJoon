//백준 5427불 틀림, 나중에 수정. 
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

// # 벽, . 빈공간, @ 불, * 상근이

//움직일 수 있는 범위인지
bool is_in_map(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < w) && (y < h);
}

//불의 맵 함수
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

	//불의 맵 확인용 코드
	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << fire_map[i][j];
		}
		cout << endl;
	}
	cout << "------------------\n";*/

	//탐색범위
	//움직일 수 있는 범위
	//. 인지
	// - 다음칸 값 > 다음칸 저장될 값
	//	맵에 저장
	return 0;
}


//사람 이동 함수
int move_human()
{
	int min_count = 1000000;
	for (int i = 0; i < 1001; i++){
		memset(is_visit[i],false,1001);
	}

	//탈출이 가능하다면 최소 이동수는 1, 따라서 0= 탈출 불가능
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
			//맵 밖이라면 혹싀 탈출인지 확인한다.
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
		//맵 초기화
		for (int hi = 0; hi < h; hi++)
		{
			for (int wi = 0; wi < w; wi++)
			{
				cin >> temp;
				//불 받았다면 큐에 저장 나중에 탐색하도록 만든다.
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
		//불의 맵 만들기 위한 bfs -각 불씨하나마다의 방문 큐 하나씩 만들자.
		//불씨가 두개 이상일 경우, (불의맵 숫자 > 다음 불씨숫자) 일때마다 방문
		//숫자가 적힌 불의 맵에서 사람의 이동bfs (다음 이동수 < 불의 숫자) 일때마다 방문
		//if 사람bfs 결과에따라 값반환
	}
	return 0;
}