#include <iostream>
#define INF 1000000000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, dp[1000001] = {0, 1};
	cin >> n;
	int flag = 1;

	if (n < 0) {
		n *= -1;
		if (n % 2 == 0)
			flag = -1;
	}

	if (n == 0) {
		cout << 0 << '\n' << 0;
		return 0;
	}

	cout << flag << '\n';

	for (int i = 2; i <= n; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2]) % INF;
	long long answer = dp[n];
	cout << answer % INF;

	return 0;
}