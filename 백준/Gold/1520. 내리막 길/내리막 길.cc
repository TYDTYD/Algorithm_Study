#include <iostream>
using namespace std;

int dx[4] = { 1,0,0,-1 }, dy[4] = { 0,1,-1,0 };
int dp[501][501];
int graph[501][501],m,n,answer = 0;
int dfs(int x, int y, int a) {
	if (x == m-1 && y == n-1)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		if (a > graph[nx][ny]) {
			dp[x][y] = dp[x][y] + dfs(x + dx[i], y + dy[i], graph[nx][ny]);
		}
	}

	return dp[x][y];
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			dp[i][j] = -1;
		}
	}

	answer = dfs(0, 0, graph[0][0]);

	cout << answer;

	return 0;
}