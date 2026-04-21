#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int tomato[1001][1001];

int main() {
	int m, n, answer = 0;
	queue<pair<int, int>> q;
	bool visited[1001][1001] = {};

	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = true;
			}
        }
	}

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + p.first;
			int ny = dy[i] + p.second;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (visited[nx][ny])
				continue;
			if (tomato[nx][ny] == -1)
				continue;
			if (tomato[nx][ny] != 0 && tomato[nx][ny] <= tomato[p.first][p.second])
				continue;
			tomato[nx][ny] = tomato[p.first][p.second] + 1;
			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cout << -1;
				return 0;
			}
			else
				answer = max(answer, tomato[i][j]);
		}
	}
	cout << answer - 1;

	return 0;
}