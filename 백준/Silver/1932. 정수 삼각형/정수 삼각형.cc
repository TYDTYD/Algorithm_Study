#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	int array[501][501],dp[501][501];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < n; i++)
		dp[n - 1][i] = array[n - 1][i];

	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j <n; j++)
			dp[i][j] = max(array[i][j] + dp[i + 1][j], array[i][j] + dp[i + 1][j + 1]);
	}

	cout << dp[0][0];

	return 0;
}