#include <iostream>
using namespace std;

void recur(int n, int c, int start, char star[500][500]) {
	if (n < c)
		return;
	int limit = 1 + (c - 1) * 4 + start;
	for (int i = start; i < limit; i++) {
		for (int j = start; j < limit; j++) {
			if (i == start || j == start || i == limit-1 || j == limit-1)
				star[i][j] = '*';
		}
	}
	recur(n, c + 1, start - 2, star);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	char star[500][500];
	for (int i = 0; i < (n - 1) * 4 + 1; i++)
		fill(star[i], star[i] + (n - 1) * 4 + 1, ' ');
	recur(n, 1, (n - 1) * 2, star);
	int limit = 1 + (n - 1) * 4;
	for (int i = 0; i < limit; i++) {
		for (int j = 0; j < limit; j++)
			cout << star[i][j];
		cout << '\n';
	}
	return 0;
}