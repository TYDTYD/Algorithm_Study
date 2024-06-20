#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, array[1001], dp[1001], answer = 0;
	fill(dp, dp + 1001, 1);
	vector<int> a[1001];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> array[i];

	for (int i = 0; i < n; i++) {
		int index = i;
		for (int j = 0; j < i; j++) {
			if (array[i] > array[j]) {
				int tmp = dp[i];
				dp[i] = max(dp[i], dp[j] + 1);
				if (tmp != dp[i])
					index = j;
			}
		}
		for (const auto& aa : a[index])
			a[i].push_back(aa);
		a[i].push_back(array[i]);
		answer = max(answer, (int)a[i].size());
	}

	for (int i = 0; i < n; i++) {
		if (answer == a[i].size()) {
			cout << answer << '\n';
			for (const auto& n : a[i])
				cout << n << " ";
			break;
		}
	}

	return 0;
}