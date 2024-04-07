#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k, answer = 1000000;
	cin >> n >> k;
	vector<int> coin(n, 0);
	int result[100001] = {};

	for (int j = 0; j < n; j++) {
		cin >> coin[j];
		result[coin[j]] = 1;
	}
	for (const auto& c : coin) {
		for (int j = 0; j <= k; j++) {
			if (j - c < 0)
				continue;
			if (result[j - c]) {
				if (result[j] != 0)
					result[j] = min(result[j], result[j - c] + 1);
				else
					result[j] = result[j - c] + 1;
			}
			if (j == k) {
				if(result[j]!=0)
					answer = min(result[j], answer);
			}
		}
	}

	if (answer == 1000000)
		cout << -1;
	else
		cout << answer;


	return 0;
}