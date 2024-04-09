#include <iostream>
#include <string>
using namespace std;

int n, m, answer = 0;
string graph[1001];
int dp[1001][1001] = {};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> graph[i];
		for (int j = 0; j < m; j++) {
			dp[i+1][j+1] = graph[i][j] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] != 0) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				answer = max(dp[i][j], answer);
			}
		}
	}

	cout << answer * answer;

	return 0;
}