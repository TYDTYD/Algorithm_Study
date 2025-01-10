#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;

	long long fibo[100] = { 1,2 };
	int idx = 0;
	vector<long long> v;

	for (int i = 0; i < 100; i++) {
		fibo[i + 2] = fibo[i + 1] + fibo[i];
		if (fibo[i + 2] > n) {
			idx = i + 1;
			break;
		}
	}

	for (int i = idx; i >= 0; i--) {
		if (n == 0)
			break;
		if (fibo[i] > n)
			continue;
		n -= fibo[i];
		v.emplace_back(fibo[i]);
	}
	
	if (v.empty() || n!=0) {
		cout << -1;
	}
	else {
		cout << v.size() << '\n';
		sort(v.begin(), v.end());
		for (const auto& sum : v)
			cout << sum << ' ';
	}

	return 0;
}