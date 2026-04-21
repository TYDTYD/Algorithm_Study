#include <iostream>
#include <queue>
using namespace std;

int dx[6] = { 1,0,-1,0,0,0 }, dy[6] = { 0,1,0,-1,0,0 }, dz[6] = { 0,0,0,0,1,-1 };

struct node {
	int x;
	int y;
	int z;
	node(int a, int b, int c) :z(a), y(b), x(c) {}
};

int main() {
	int graph[101][101][101];
	int visited[101][101][101];
	int answer = 0;
	int m, n, h;
	cin >> m >> n >> h;

	queue<node> q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				visited[i][j][k] = 0;
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1) {
					q.push(node(i, j, k));
					visited[i][j][k] = 1;
				}
			}
		}
	}

	while (!q.empty()) {
		node t = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = dx[i] + t.x;
			int ny = dy[i] + t.y;
			int nz = dz[i] + t.z;
			
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
				continue;
			if (visited[nz][ny][nx] >= 1)
				continue;
			if (graph[nz][ny][nx] == -1)
				continue;
			
			visited[nz][ny][nx] = visited[t.z][t.y][t.x] + 1;
			graph[nz][ny][nx] = 1;
			q.push(node(nz, ny, nx));
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (graph[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				answer = max(answer, visited[i][j][k]);
			}
		}
	}

	cout << answer - 1;

	return 0;
}