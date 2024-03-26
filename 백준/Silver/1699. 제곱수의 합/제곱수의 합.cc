#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, dp[100001], answer = 0;
	vector<int> v;
	cin >> n;

	for (int i = 0; i <=n; i++)
		dp[i] = i;

	for (int i = 1; i < 316; i++) {
		dp[i * i] = 1;
		v.push_back(i * i);
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 315; j++) {
			if (i + v[j] > 100000)
				continue;
			dp[i + v[j]] = min(dp[i + v[j]], dp[i] + 1);
		}
	}

	cout << dp[n];

	return 0;
}