#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k, n;
vector<int> len;

bool solve(long long x) {
	long long cur = 0;
	for (int i = 0; i < k; i++)
		cur += len[i] / x;
	return cur >= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		int length;
		cin >> length;
		len.push_back(length);
	}

	long long start = 1;
	long long end = 0x7fffffff;
	while (start < end) {
		long long mid = (start + end + 1) / 2;
		if (solve(mid))
			start = mid;
		else
			end = mid - 1;
	}
	cout << start;

	return 0;
}