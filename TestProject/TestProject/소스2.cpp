#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> tree[10];
bool visit[10];
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ",x);
		for(int i =0; i<x.)
	}
}

int main()
{
	tree[1].push_back(2);
	tree[1].push_back(3);

	tree[2].push_back(1);
	tree[2].push_back(4);
	tree[2].push_back(5);

	tree[3].push_back(1);
	tree[3].push_back(6);
	tree[3].push_back(7);

	tree[4].push_back(2);
	tree[4].push_back(8);
	tree[4].push_back(9);

	tree[5].push_back(2);
	tree[5].push_back(10);

	tree[6].push_back(3);
	tree[7].push_back(3);
	tree[8].push_back(4);
	tree[9].push_back(4);
	tree[10].push_back(5);

	bfs(1);
	return 0;
}