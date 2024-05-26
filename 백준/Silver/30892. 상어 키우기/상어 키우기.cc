#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n, k, t;
	vector<long long> shark;
	cin >> n >> k >> t;
	for (int i = 0; i < n; i++) {
		long long size;
		cin >> size;
		shark.push_back(size);
	}

	sort(shark.begin(), shark.end());
	while (k != 0) {
		long long index = lower_bound(shark.begin(), shark.end(), t) - shark.begin();
		if (index <= 0)
			break;
		t += shark[index - 1];
		shark.erase(shark.begin() + index - 1);
		k--;
	}
	
	cout << t;

	return 0;
}