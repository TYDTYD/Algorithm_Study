#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, number[2001] = {};
	bool result[2001][2001] = {};
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> number[i];
		result[i][i] = true;
	}

	for (int i = 1; i <= n - 1; i++) {
		if (number[i] == number[i + 1])
			result[i][i + 1] = true;
	}


	for (int i = n - 2; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (number[i] == number[j] && result[i+1][j-1])
				result[i][j] = true;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << result[s][e] << '\n';
	}

	return 0;
}