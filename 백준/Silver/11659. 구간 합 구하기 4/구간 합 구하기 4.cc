#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int dp[100000], n, m, num;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i == 0)
			dp[i] = num;
		else
			dp[i] = num + dp[i - 1];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1)
			cout << dp[b-1] << "\n";
		else
			cout << dp[b-1] - dp[a-2] << "\n";
	}

	return 0;
}