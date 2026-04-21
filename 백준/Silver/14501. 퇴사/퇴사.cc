#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int dp[20] = {};
	int time[20], money[20];

	for (int i = 0; i < n; i++) {
		cin >> time[i] >> money[i];
	}

	for (int i = 0; i < n; i++) {
		if (time[i]+i <= n)
			dp[i] = money[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (j + time[j] <= i) {
				if (i + time[i] > n)
					dp[i] = max(dp[i], dp[j]);
				else
					dp[i] = max(dp[i], money[i] + dp[j]);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
		answer = max(answer, dp[i]);


	cout << answer;
	return 0;
}