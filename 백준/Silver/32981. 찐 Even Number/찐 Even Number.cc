#include <iostream>
#define MOD (1000000000+7)
using namespace std;

long long dp[10000004] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	dp[1] = 5;
	dp[2] = 20;

	for (int i = 2; i < 10000000; i++)
		dp[i + 1] = (dp[i]*(long long)5) % MOD;

	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}