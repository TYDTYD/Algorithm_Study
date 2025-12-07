#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> lamp;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		lamp.push_back(x);
	}

	int answer = 0;

	int pos = 0;
	int result = 0;


	for (int i = 0; i < m; i++) {
		if (i - 1 >= 0) {
			double mid = (lamp[i] - lamp[i - 1]) / 2.0;
			result = ceil(mid);
		}
		if (i == 0) {
			int offset = lamp[i];
			result = max(result, offset);
		}
		if (i == m - 1) {
			int offset = n - lamp[i];
			result = max(result, offset);
		}
		answer = max(answer, result);
	}

	cout << answer;
	return 0;
}