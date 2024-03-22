#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, sit[41] = {}, result[41] = {};
	long long answer = 1, dp[41] = {};
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int vip;
		cin >> vip;
		sit[vip] = 1;
	}

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int idx = 1;
	for (int i = 1; i <= n; i++) {
		if (!sit[i])
			result[i] = dp[idx++];
		else {
			idx = 1;
			result[i] = 1;
		}
	}

	if (m == 0)
		cout << result[n];
	else if (m == n)
		cout << 1;
	else {
		for (int i = 2; i <=n; i++) {
			if (sit[i])
				answer *= result[i - 1];
		}
		answer *= result[n];

		cout << answer << endl;
	}

	return 0;
}