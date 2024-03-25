#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = -1;
	int test = 1;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		long long dp[100001][3] = {}, cost[100001][3] = {};
		for (int i = 0; i < n; i++)
			fill(dp[i], dp[i] + 3, 10000000);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> cost[i][j];
			}
		}

		dp[0][1] = cost[0][1];
		dp[0][2] = cost[0][2] + cost[0][1];

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 0)
					dp[i][j] = min(cost[i][j] + dp[i - 1][j], cost[i][j] + dp[i - 1][j + 1]);
				else if (j == 1) {
					long long mn1 = min(cost[i][j] + dp[i - 1][j - 1], cost[i][j] + dp[i - 1][j]);
					long long mn2 = min(mn1, cost[i][j] + dp[i][j - 1]);
					dp[i][j] = min(mn2, cost[i][j] + dp[i - 1][j + 1]);
				}
				else {
					long long mn = min(cost[i][j] + dp[i - 1][j - 1], cost[i][j] + dp[i][j - 1]);
					dp[i][j] = min(mn, cost[i][j] + dp[i - 1][j]);
				}
			}
		}
		
		cout << test << ". " << dp[n - 1][1] << '\n';
		test++;
	}
	return 0;
}