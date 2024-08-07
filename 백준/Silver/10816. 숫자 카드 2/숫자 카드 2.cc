#include <iostream>
#include <algorithm>

using namespace std;

int a[500001];

int lower_idx(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		if (a[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	return start;
}

int upper_idx(int target, int len) {
	int start = 0;
	int end = len;
	while (start < end) {
		int mid = (start + end) / 2;
		if (a[mid] > target)
			end = mid;
		else
			start = mid + 1;
	}
	return start;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		cout << upper_idx(t, n) - lower_idx(t, n) << " ";
	}

	return 0;
}