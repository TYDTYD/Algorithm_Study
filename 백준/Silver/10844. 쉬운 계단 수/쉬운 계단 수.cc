#include <iostream>
#define INF 1000000000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	long long dp[101][10] = {};
	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j != 0 && j != 9)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % INF;
			else if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % INF;
			else
				dp[i][j] = dp[i - 1][j - 1] % INF;
		}
	}
	long long answer = 0;
	for (int i = 0; i < 10; i++)
		answer += dp[n - 1][i];

	cout << answer % INF;

	return 0;
}