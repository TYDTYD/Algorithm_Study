#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		long long n, dp[1000001] = {};
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		cin >> n;
		for (int j = 4; j <= n; j++)
			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009;
		cout << dp[n]%1000000009 << endl;
	}

	return 0;
}