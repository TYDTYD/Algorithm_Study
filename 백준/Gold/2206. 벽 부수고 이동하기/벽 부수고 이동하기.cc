#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, graph[1001][1001];
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			graph[i][j] = tmp[j]-'0';
		}
	}

	struct node {
		int x;
		int y;
		bool destroy = false;
		node(int a, int b, bool c) {
			x = a;
			y = b;
			destroy = c;
		}
	};

	queue<node> q;
	bool visited1[1001][1001] = {};
	bool visited2[1001][1001] = {};
	int count[1001][1001] = {};
	count[0][0] = 1;
	visited1[0][0] = true;
	visited2[0][0] = true;
	node start(0, 0, false);
	q.push(start);

	while (!q.empty()) {
		node p = q.front();
		q.pop();
		if (p.x == n - 1 && p.y == m - 1)
			break;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + p.x;
			int ny = dy[i] + p.y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (p.destroy && graph[nx][ny])
				continue;
			if (!p.destroy && visited1[nx][ny])
				continue;
			if (p.destroy && (visited1[nx][ny] || visited2[nx][ny]))
				continue;
			if (!p.destroy)
				visited1[nx][ny] = true;
			else
				visited2[nx][ny] = true;
			if (graph[nx][ny]) {
				node newP(nx, ny, true);
				q.push(newP);
			}
			else {
				node newP(nx, ny, p.destroy);
				q.push(newP);
			}
			count[nx][ny] = count[p.x][p.y] + 1;
		}
	}

	if (count[n - 1][m - 1] == 0)
		cout << -1;
	else
		cout << count[n - 1][m - 1];

	return 0;
}