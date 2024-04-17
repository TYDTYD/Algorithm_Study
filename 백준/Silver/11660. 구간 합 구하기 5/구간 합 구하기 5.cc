#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m,map[1050][1050], dp[1050][1050] = {};
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			sum += map[i][j];
			dp[i][j] = dp[i - 1][j] + sum;
		}
	}


	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == 1 && x2 == 1 && y1 == 1 && y2 == 1) {
			cout << dp[1][1] << '\n';
			continue;
		}
		if (x1 == 1 && y1 == 1) {
			cout << dp[x2][y2] << '\n';
		}
		else if (x1 == 1) {
			cout << dp[x2][y2] - dp[x2][y1 - 1] << '\n';
		}
		else if (y1 == 1) {
			cout << dp[x2][y2] - dp[x1 - 1][y2] << '\n';
		}
		else
			cout << dp[x2][y2] - (dp[x2][y1 - 1] + dp[x1 - 1][y2]) + dp[x1-1][y1-1] << '\n';
	}

	return 0;
}