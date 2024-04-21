#include <iostream>
#define INF 1000000003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k, answer = 0;
	long long dp[1010][1010][2][2] = {};
	cin >> n >> k;

	dp[1][0][1][0] = 1;
	dp[1][1][0][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int p = 0; p < 2; p++) {
				// 선택을 했을때
				if (p == 0) {
					if (j >= 1) {
						dp[i][j][p][0] += dp[i - 1][j - 1][1][0] % INF;
						dp[i][j][p][1] += dp[i - 1][j - 1][1][1] % INF;
					}
				}
				else {
					dp[i][j][p][0] += dp[i - 1][j][0][0] % INF;
					dp[i][j][p][1] += dp[i - 1][j][0][1] % INF;
					dp[i][j][p][0] += dp[i - 1][j][1][0] % INF;
					dp[i][j][p][1] += dp[i - 1][j][1][1] % INF;
				}
			}
		}
	}

	cout << (dp[n][k][0][0] + dp[n][k][1][0] + dp[n][k][1][1]) % INF;

	return 0;
}