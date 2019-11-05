#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[1001];
bool visited[1001];
int cnt;

void bfs(int n)
{
	queue<int> q;
	visited[n] = true;
	q.push(n);
	while (!q.empty()) {
		int t = q.front();
		for (int i = 0; i < graph[t].size(); i++) {
			if (!visited[(graph[t][i])]) {
				visited[(graph[t][i])] = true;
				q.push((graph[t][i]));
			}
		}
		q.pop();
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1, from, to; i <= M; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}