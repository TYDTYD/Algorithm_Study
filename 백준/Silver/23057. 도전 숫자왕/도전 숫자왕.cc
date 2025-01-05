#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int arr[20];

void Backtracking(int k, int n, int num) {
	if (k == n + 1)
		return;
	if(num)
		s.insert(num);
	Backtracking(k + 1, n, num + arr[k]);
	Backtracking(k + 1, n, num);
}

int main() {
	int n, m = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m += arr[i];
	}

	Backtracking(0, n, 0);

	cout << m - s.size();

	return 0;
}