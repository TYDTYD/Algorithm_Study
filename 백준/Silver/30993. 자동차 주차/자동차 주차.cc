#include <iostream>
using namespace std;

void solve(int n, int m, int a, int b, int c, int& answer) {
	if (n == m) {
		answer++;
		return;
	}
		
	if (a != 0)
		solve(n, m + 1, a - 1, b, c, answer);
	if (b != 0)
		solve(n, m + 1, a, b - 1, c, answer);
	if (c != 0)
		solve(n, m + 1, a, b, c - 1, answer);
}

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int answer = 0;
	solve(n, 0, a, b, c, answer);
	cout << answer;
	return 0;
}