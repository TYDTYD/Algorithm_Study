#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& graph, int h, int n, int x, int y, bool visited[101][101]) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;
			if (h >= graph[nx][ny])
				continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<vector<int>> graph(n);
	bool visited[101][101] = {};
	int max_h = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int h;
			cin >> h;
			graph[i].push_back(h);
			max_h = max(h, max_h);
		}
	}

	int answer = 0, result = 0;
	for (int i = 0; i <= max_h; i++) {
		answer = max(answer, result);
		result = 0;
		for (int j = 0; j < n; j++)
			fill(visited[j], visited[j] + n + 1, false);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (visited[j][k] || i >= graph[j][k])
					continue;
				bfs(graph, i, n, j, k, visited);
				result++;
			}
		}
	}

	cout << answer;

	return 0;
}