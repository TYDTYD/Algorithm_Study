#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k, sum1 = 0, sum2 = 0;
	cin >> n >> k;

	long long answer = 0;

	vector<int> bag1, bag2;

	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		bag1.emplace_back(weight);
		sum1 += weight;
	}

	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		bag2.emplace_back(weight);
		sum2 += weight;
	}

	for (int i = 0; i < k; i++) {
		if (sum1 == 0 && sum2 == 0)
			continue;

		if (bag1.empty()) {
			sum2 -= bag2.back();
			bag2.pop_back();
		}
		else if (bag2.empty()) {
			sum1 -= bag1.back();
			bag1.pop_back();
		}
		else if (sum1 > sum2) {
			sum1 -= bag1.back();
			bag1.pop_back();
		}
		else {
			sum2 -= bag2.back();
			bag2.pop_back();
		}
	}

	answer = sum1 > sum2 ? sum1 : sum2;
	cout << answer;

	return 0;
}