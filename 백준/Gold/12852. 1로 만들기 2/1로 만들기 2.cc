#include <iostream>

using namespace std;

int dp[1000000], route[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		route[i] = i - 1;
		if (i % 2 == 0 && dp[i]>dp[i/2]+1) {
			route[i] = i / 2;
			dp[i] = dp[i / 2] + 1;
		}
		if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
			route[i] = i / 3;
			dp[i] = dp[i / 3] + 1;
		}
	}

	cout << dp[n] << "\n";
	int cur = n;
	while (true) {
		cout << cur << ' ';
		if (cur == 1)
			break;
		cur = route[cur];
	}

	return 0;
}