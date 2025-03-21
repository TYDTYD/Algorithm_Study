#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		v.push_back(card);
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = v[i] + v[j] + v[k];
				if (sum > m)
					continue;
				answer = max(answer, sum);
			}
		}
	}
	cout << answer;
	return 0;
}