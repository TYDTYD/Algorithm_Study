#include <iostream>

using namespace std;

int main() {
	int T;

	cin >> T;

	int k, n, dp[20][20];

	for (int i = 0; i < T; i++) {
		cin >> k >> n;

		for (int i = 0; i < 20; i++) 
			fill(dp[i], dp[i] + 20, 0);

		for (int i = 0; i < 20; i++)
			dp[0][i] = i;

		for (int i = 1; i < k+1; i++) {
			for (int j = 1; j < n+1; j++) {
				for (int l = 0; l < j+1; l++) {
					dp[i][j] += dp[i-1][l];
				}
			}
		}
		cout << dp[k][n] << '\n';
	}
}