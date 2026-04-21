#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, a[1001], dp[1001], answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j])
				dp[i] = max(dp[i], a[i] + dp[j]);
		}
	}

	for (int i = 0; i < n; i++) {
		answer = max(answer, dp[i]);
	}	

	cout << answer;

	return 0;
}