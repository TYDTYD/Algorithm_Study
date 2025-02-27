#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e7
using namespace std;

int answer = INF, w = 0;
vector<vector<int>> v(2, vector<int>());
int dp[10001][3];

// 왼쪽 오른쪽 조합
int sum_w(int x, int y) {
	if (x + 1 >= v[y].size())
		return INF;
	return v[y][x] + v[y][x + 1];
}

// 위 아래 조합
int sum_h(int x) {
	return v[0][x] + v[1][x];
}

bool possible(int w, int sum) {
	if (w >= sum)
		return true;
	return false;
}

void init() {
	answer = INF;
	for (int i = 0; i < 2; i++)
		v[i].clear();
}

void initDP(int n, int m, int w) {
	for (int i = 0; i <= n; i++)
		fill(dp[i], dp[i] + 3, INF);
	if (m == 0) {
		for (int i = 0; i < 3; i++)
			dp[1][i] = 0;
	}
	else if (m == 1) {
		dp[1][0] = 2;
		dp[1][2] = 1;
	}
	else if (m == 2) {
		dp[1][0] = 2;
		dp[1][1] = 1;
	}
	else {
		for (int i = 0; i < 3; i++)
			dp[0][i] = 0;
	}
}

void solve(int n, int m, int w) {
	initDP(n, m, w);
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i][0], dp[i - 1][0] + (possible(w, sum_h(i - 1)) ? 1 : 2));
				
		dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);

		dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
		if (i > 1) {
			dp[i][0] = min(dp[i][0], dp[i - 2][0] + 4);
			dp[i][0] = min(dp[i][0], dp[i - 2][0] + (possible(w, sum_w(i - 2, 0)) ? 1 : 2) + (possible(w, sum_w(i - 2, 1)) ? 1 : 2));
			dp[i][0] = min(dp[i][0], dp[i - 1][2] + (possible(w, sum_w(i - 2, 1)) ? 2 : 3));
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + (possible(w, sum_w(i - 2, 0)) ? 2 : 3));

			dp[i][1] = min(dp[i][1], dp[i - 1][2] + (possible(w, sum_w(i - 2, 1)) ? 1 : 2));

			dp[i][2] = min(dp[i][2], dp[i - 1][1] + (possible(w, sum_w(i - 2, 0)) ? 1 : 2));
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, firstTop, firstDown, LastTop, LastDown;
		cin >> n >> w;

		init();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				int enemy;
				cin >> enemy;
				v[i].emplace_back(enemy);
				if (i == 0 && j == 0)
					firstTop = enemy;
				else if (i == 1 && j == 0)
					firstDown = enemy;
				else if (i == 0 && j == n - 1)
					LastTop = enemy;
				else if (i == 1 && j == n - 1)
					LastDown = enemy;
			}
		}

		if (n == 1) {
			if (w >= firstTop + firstDown)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
			continue;
		}

		if (w >= firstTop + LastTop && w >= firstDown + LastDown) {
			solve(n, 0, w);
			answer = min(answer, dp[n - 1][0] + 2);
		}
		if (w >= firstTop + LastTop) {
			solve(n, 1, w);
			answer = min(answer, dp[n][1]);
		}
		if (w >= firstDown + LastDown) {
			solve(n, 2, w);
			answer = min(answer, dp[n][2]);
		}
		solve(n,3,w);
		answer = min(answer, dp[n][0]);
		cout << answer << '\n';
	}
	return 0;
}