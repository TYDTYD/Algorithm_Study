#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> velocity(n);
	for (int i = n - 1; i >= 0; i--) {
		long long v;
		cin >> v;
		velocity[i] = v;
	}

	long long answer = 1;
	long long current = 1;

	for (int i = 1; i < n; i++) {
		if (current > velocity[i])
			current = velocity[i];
		else if (current < velocity[i])
			current++;
		answer += current;
	}

	cout << answer;
	return 0;
}