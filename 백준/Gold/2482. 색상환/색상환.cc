#include <iostream>
#define INF 1000000003
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k;
	long long dp[1010][1010] = {};
	cin >> n >> k;


	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++)
			dp[i][j]= dp[i - 2][j - 1] + dp[i - 1][j] % INF;
	}

	cout << (dp[n-1][k] + dp[n-3][k-1]) % INF;

	return 0;
}