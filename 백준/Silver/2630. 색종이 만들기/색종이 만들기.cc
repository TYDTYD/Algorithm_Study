#include <iostream>
#include <vector>
using namespace std;

void solve(int start, int end, int h_start, int h_end, int half, vector<vector<int>>& graph, int& blue, int& white) {
	int sum = 0, c = 0;
	for (int i = start; i <= end; i++) {
		for (int j = h_start; j <= h_end; j++) {
			if (graph[i][j])
				sum++;
			c++;
		}
	}

	if (sum == c)
		blue++;
	else if (sum == 0)
		white++;
	else {
		int mid = half + start - 1;
		int hmid = half + h_start - 1;
		solve(start, mid, h_start, hmid, half / 2, graph, blue, white);
		solve(start, mid, hmid + 1, h_end, half / 2, graph, blue, white);
		solve(mid + 1, end, h_start, hmid, half / 2, graph, blue, white);
		solve(mid + 1, end, hmid + 1, h_end, half / 2, graph, blue, white);
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, blue = 0, white = 0;
	cin >> n;
	vector<vector<int>> graph(n + 1, (vector<int>(n + 1, 0)));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> graph[i][j];
	}

	solve(1, n, 1, n, n / 2, graph, blue, white);
	cout << white << '\n' << blue;

	return 0;
}