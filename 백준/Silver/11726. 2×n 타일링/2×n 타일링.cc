#include <iostream>
using namespace std;

int main()
{
	int n;
	long long dp[1010] = {};
	dp[0] = 1;
	cin >> n;
	int tile[2] = { 1, 2 };

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i + tile[j]] = (dp[i+tile[j]] + dp[i])%10007;
		}
	}
	cout << dp[n];
}