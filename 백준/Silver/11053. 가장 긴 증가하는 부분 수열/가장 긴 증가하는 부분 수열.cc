#include <iostream>
using namespace std;

int main() {
	int n, a[1001], dp[1001], answer = 1;
	cin >> n;

	fill(dp, dp + 1001, 1);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
}