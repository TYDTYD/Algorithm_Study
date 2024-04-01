#include <iostream>
#include <queue>
using namespace std;

int n, m, d, graph[20][20], answer = 0;
int dx[3] = { 0,-1,0 }, dy[3] = { -1,0,1 };

struct node {
	int x;
	int y;
	int d;
	node(int a, int b, int dist) {
		x = a;
		y = b;
		d = dist;
	}
};

void solve(int t, int c) {
	if (t == 3) {
		int result = 0, g[20][20];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				g[i][j] = graph[i][j];
		}
		
		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (graph[n][j]) {
					queue<node> q;
					q.push(node(i, j, 1));
					while (!q.empty()) {
						node w = q.front();
						q.pop();
						if (g[w.x][w.y]) {
							if (g[w.x][w.y] == 1)
								result++;
							g[w.x][w.y] += 1;
							break;
						}
						for (int i = 0; i < 3; i++) {
							int nx = w.x + dx[i];
							int ny = w.y + dy[i];
							int distance = w.d + 1;
							if (nx < 0 || nx >= n || ny < 0 || ny >= m)
								continue;
							if (distance > d)
								continue;
							q.push(node(nx, ny, distance));
						}
					}
				}
			}
			for (int a = 0; a < i+1; a++) {
				for (int b = 0; b < m; b++) {
					if (g[a][b] > 1)
						g[a][b] = 0;
				}
			}
		}

		answer = max(answer, result);
		
		return;
	}
	if (c >= m)
		return;
	graph[n][c] = 1;
	solve(t + 1, c + 1);
	graph[n][c] = 0;
	solve(t, c + 1);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> graph[i][j];
	}

	solve(0, 0);
	cout << answer;

	return 0;
}