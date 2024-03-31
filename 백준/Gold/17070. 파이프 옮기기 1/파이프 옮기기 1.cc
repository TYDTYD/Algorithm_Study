#include <iostream>

using namespace std;

int graph[20][20], n, answer = 0;

void dfs(int x, int y, int d) {
	if (x < 0 || x >= n || y < 0 || y >= n)
		return;
	if (d == 1) {
		if (graph[x][y - 1] || graph[x][y])
			return;
	}
	else if (d == 2) {
		if (graph[x - 1][y] || graph[x][y])
			return;
	}
	else {
		if (graph[x - 1][y] || graph[x - 1][y - 1] || graph[x][y - 1] || graph[x][y])
			return;
	}

	if (x == n - 1 && y == n - 1) {
		answer++;
		return;
	}

	if (d == 1) {
		dfs(x, y + 1, 1);
		dfs(x + 1, y + 1, 3);
	}
	else if (d == 2) {
		dfs(x + 1, y, 2);
		dfs(x + 1, y + 1, 3);
	}
	else if (d == 3) {
		dfs(x, y + 1, 1);
		dfs(x + 1, y, 2);
		dfs(x + 1, y + 1, 3);
	}

	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}

	dfs(0, 1, 1);

	cout << answer;

	return 0;
}