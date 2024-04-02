#include <iostream>

using namespace std;

int graph[10][10], answer = 101, c[5] = {};

bool check(int x, int y, int z) {
	for (int i = x; i <= x + z; i++) {
		for (int j = y; j <= y + z; j++) {
			if (!graph[i][j])
				return false;
		}
	}
	return true;
}

bool range_check(int x, int y) {
	if (x < 0 || x >= 10 || y < 0 || y >= 10)
		return false;
	return true;
}

void fill_graph(int x, int y, int z, int n) {
	for (int i = x; i <= x + z; i++) {
		for (int j = y; j <= y + z; j++) {
			graph[i][j] = n;
		}
	}
}

bool empty_graph() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (graph[i][j])
				return false;
		}
	}
	return true;
}

void solve(int x, int y, int z, int result) {
	if (c[z] > 5)
		return;

	if (result > answer)
		return;

	if (empty_graph()) {
		answer = min(answer, result);
		return;
	}

	for (int i = x; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (graph[i][j]) {
				for (int k = 4; k >= 0; k--) {
					if (range_check(i + k, j + k) && check(i, j, k)) {
						fill_graph(i, j, k, 0);
						c[k] += 1;
						solve(i, j, k, result + 1);
						fill_graph(i, j, k, 1);
						c[k] -= 1;
					}
				}
				return;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cin >> graph[i][j];
	}

	solve(0, 0, 0, 0);

	if (answer == 101)
		cout << -1;
	else
		cout << answer;

	return 0;
}