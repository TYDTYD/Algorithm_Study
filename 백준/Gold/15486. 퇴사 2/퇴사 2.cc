#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int time[1500001], money[1500001], dp[1500001] = {};

	for (int i = 0; i < n; i++) {
		cin >> time[i] >> money[i];
	}

	for (int i = n-1; i >= 0; i--) {
		if (i+time[i] > n)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i + 1], money[i] + dp[i+time[i]]);
	}
	int answer = 0;

	for (int i = 0; i < n; i++)
		answer = max(answer, dp[i]);

	cout << answer;

	return 0;
}