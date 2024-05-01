#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, graph[101][101];
	long long dp[101][101] = {};

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1)
				break;
			if (dp[i][j] != 0) {
				int idx = graph[i][j];
				if (j + idx < n)
					dp[i][j + idx] += dp[i][j];
				if (i + idx < n)
					dp[i + idx][j] += dp[i][j];
			}
		}
	}

	cout << dp[n-1][n-1];
	return 0;
}