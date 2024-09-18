#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, arr[10001] = {};
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int front = 0, back = 0, answer = 0;

	if (n == 1) {
		if (arr[0] == m)
			cout << 1;
		else
			cout << 0;
		return 0;
	}

	int num = arr[front];

	while (back<n) {
		if (num == m) {
			answer++;
			num -= arr[front];
			back++;
			num += arr[back];
			front++;
		}
		else if (num < m) {
			back++;
			num += arr[back];
		}
		else {
			num -= arr[front];
			front++;
		}
	}

	cout << answer;

	return 0;
}