#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
public:
	int N; // ������ ����
	vector<vector<int>> adj; // ���� ����Ʈ

	// ������
	Graph() : N(0) {}	//������ ���ÿ� ����� -> ������ ������ȣ����� ���� �ʾƵ� �� (?)
	Graph(int n) : N(n) { adj.resize(N); }

	// ���� �߰� �Լ�
	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// ��� ����Ʈ�� ������ ���� ��ȣ ����
	void sortList() {
		for (int i = 0; i < N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	// �ʺ� �켱 Ž��
	void bfs() {
		vector<bool> visited(N, false); // �湮 ���θ� �����ϴ� �迭
		queue<int> Q;
		Q.push(0);
		visited[0] = true;
		// Ž�� ����
		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			cout << "node " << curr << " visited" << endl;
			for (int next : adj[curr]) {
				if (!visited[next]) {
					visited[next] = true;
					Q.push(next);
				}
			}
		}
	}
};

int main() {
	Graph G(9);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 5);
	G.addEdge(3, 4);
	G.addEdge(4, 5);
	G.addEdge(2, 6);
	G.addEdge(2, 8);
	G.addEdge(6, 7);
	G.addEdge(6, 8);
	G.sortList();
	G.bfs();
}