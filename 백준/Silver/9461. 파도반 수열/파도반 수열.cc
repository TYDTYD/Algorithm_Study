#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	long long dp[100] = { 1,1,1,2,2 };

	while (T) {
		T--;
		int N;
		cin >> N;
		for (int i = 5; i < N; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[N-1] << '\n';
	}
	return 0;
}