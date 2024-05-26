#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n, k, t;
	vector<int> shark;
	cin >> n >> k >> t;
	for (int i = 0; i < n; i++) {
		int size;
		cin >> size;
		shark.push_back(size);
	}

	sort(shark.begin(), shark.end());
	while (k-- != 0) {
		int index = lower_bound(shark.begin(), shark.end(), t) - shark.begin();
		if (index <= 0)
			break;
		t += shark[index - 1];
		shark.erase(shark.begin() + index - 1);
	}

	cout << t;

	return 0;
}