#include <iostream>
#include <queue>
#include <vector>
#include <array>
using namespace std;

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int solve(int n, int x, int y, int destX, int destY) {
	bool visited[301][301] = {};
	queue<array<int,3>> q;
	q.push({ x, y, 0 });
	visited[x][y] = true;
	while (!q.empty()) {
		array<int, 3> p = q.front();
		if (p[0] == destX && p[1] == destY)
			return p[2];
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = p[0] + dx[i];
			int ny = p[1] + dy[i];
			int c = p[2];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;
			q.push({ nx, ny, c + 1 });
			visited[nx][ny] = true;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int l, x, y, dx, dy;
		cin >> l;
		cin >> x >> y;
		cin >> dx >> dy;
		cout << solve(l, x, y, dx, dy) << '\n';
	}
	return 0;
}