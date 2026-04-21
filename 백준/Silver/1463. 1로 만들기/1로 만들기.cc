#include <iostream>

using namespace std;

int dp[1000000];

int main() {
	int n;
	cin >> n;
	fill(dp, dp+n, n+1);

	for (int i = n; i > 0; i--) {
		if (i % 3 == 0)
			dp[i / 3] = min(dp[i] + 1, dp[i / 3]);
		if (i % 2 == 0)
			dp[i / 2] = min(dp[i] + 1, dp[i / 2]);
		dp[i - 1] = min(dp[i] + 1, dp[i - 1]);
	}

	cout << dp[1];

	return 0;
}