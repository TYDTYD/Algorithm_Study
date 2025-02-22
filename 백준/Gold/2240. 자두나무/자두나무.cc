#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, w;
	cin >> t >> w;
	int tree[1001], dp[2][1001][32];

	for (int i = 1; i <= t; i++)
		cin >> tree[i];

	for (int i = 0; i < 1001; i++){
		for (int j = 0; j < 32; j++) {
			dp[0][i][j] = 0;
			dp[1][i][j] = 0;
		}
	}
	
	if (tree[1] == 1)
		dp[0][1][1] = 1;
	else
		dp[1][1][1] = 1;

	for (int i = 2; i <= t; i++) {
		for (int j = 1; j <= w+1; j++) {
			if (tree[i] == 1) {
				if (i == 2 && j == 2)
					continue;
				dp[0][i][j] = max(dp[0][i - 1][j] + 1, dp[1][i - 1][j - 1] + 1);
				dp[1][i][j] = dp[1][i - 1][j];
			}
			else {
				dp[0][i][j] = dp[0][i - 1][j];
				dp[1][i][j] = max(dp[0][i - 1][j - 1] + 1, dp[1][i - 1][j] + 1);
			}
		}
	}

	int answer = 0;

	for (int i = 0; i <= w + 1; i++)
		answer = max(answer, max(dp[0][t][i], dp[1][t][i]));

	cout << answer;

	return 0;
}