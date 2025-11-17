#include <iostream>
#include <vector>
using namespace std;

int index[1000001] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[i] = a;
		index[a]++;
	}

	int x;
	cin >> x;
	int answer = 0;

	for (const auto& v : num) {
		if (v >= x)
			continue;
		if (x - v > 1000000)
			continue;
		index[x - v] > 0 ? answer++ : answer;
	}

	cout << answer / 2;
	return 0;
}