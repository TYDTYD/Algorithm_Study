#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m, startX, startY, endX, endY, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool visited[4][201][201] = {};
int answer = 0;


struct route {
	int x;
	int y;
	int dir;
	int time;
	route(int _x, int _y, int _dir, int _time) {
		x = _x;
		y = _y;
		dir = _dir;
		time = _time;
	}
};

void bfs(vector<string>& graph) {
	queue<route> q;
	q.push(route(startX - 1, startY - 1, 0, 0));
	visited[0][startX - 1][startY - 1] = true;
	while (!q.empty()) {
		route p = q.front();
		q.pop();
		int dir = (p.time + 1) % 4;
		if (p.x == endX - 1 && p.y == endY - 1) {
			answer = p.time;
			break;
		}
		if (!visited[dir][p.x][p.y])
			q.push(route(p.x, p.y, dir, p.time + 1));

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + p.x;
			int ny = dy[i] + p.y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (graph[nx][ny] != '.')
				continue;
			if (visited[dir][nx][ny])
				continue;
			visited[dir][nx][ny] = true;
			q.push(route(nx, ny, dir, p.time + 1));
		}
	}

	return;
}

int main() {
	cin >> n >> m;
	cin >> startX >> startY >> endX >> endY;
	vector<string> graph(n, "");

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		graph[i] += s;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (graph[j][k] >= '0') {
					char dir = graph[j][k];
					int x = j;
					int y = k;
					while (true) {
						int nx = dx[(dir + i) % 4] + x;
						int ny = dy[(dir + i) % 4] + y;
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							break;
						if (graph[nx][ny] != '.')
							break;
						visited[i][nx][ny] = true;
						x = nx;
						y = ny;
					}
				}
			}
		}
	}

	bfs(graph);

	answer!=0 ? cout << answer : cout << "GG";

	return 0;
}