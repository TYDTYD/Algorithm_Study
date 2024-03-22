#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	int dp[1001][10] = {};

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k] % 10007;
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < 10; i++)
		answer += dp[n][i];

	cout << answer % 10007;

	return 0;
}