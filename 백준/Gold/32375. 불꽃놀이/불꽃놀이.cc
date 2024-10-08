#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <long long> v;
	for (int i = 0; i < n; i++) {
		long long p;
		cin >> p;
		v.emplace_back(p);
	}
	sort(v.begin(), v.end());
	auto it = lower_bound(v.begin(), v.end(), k);
	int answer = v.end() - it;

	if (answer == n) {
		cout << n;
		return 0;
	}

	int front = 0;
	int back = it - v.begin();
	long long sum = v[front] + v[--back];
	while (front < back) {
		if (sum >= k) {
			answer++;
			sum = v[++front] + v[--back];
		}
		else {
			sum -= v[front++];
			sum += v[front];
		}
	}

	if (answer)
		cout << answer;
	else
		cout << -1;

	return 0;
}