#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<vector<int>> score(2, vector<int>(n, 0));
		vector<vector<int>> dp(n, vector<int>(3, 0));
		for (int j = 0; j < 2; j++) {
			for(int k=0; k<n; k++)
				cin >> score[j][k];
		}
		dp[0][0] = score[0][0];
		dp[0][1] = score[1][0];
		for (int j = 1; j < n; j++) {
			dp[j][0] = score[0][j] + max(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = score[1][j] + max(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = max(dp[j - 1][0], dp[j - 1][1]);
		}

		cout << max({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }) << '\n';
	}
	return 0;
}