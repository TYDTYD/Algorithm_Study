#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_map<int, int> result;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int studentNum;
			cin >> studentNum;
			result[studentNum]++;
		}
	}

	int answer = 0;
	for (const auto& r : result) {
		if (r.second >= m)
			answer++;
	}

	cout << answer;
	return 0;
}