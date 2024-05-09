#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, k;
	int a[6] = { 0,1,2,3,4,5 };
	cin >> n >> m >> k;

	int graph[51][51] = {};
	int rotation[6][3] = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> graph[i][j];
	}

	for (int l = 0; l < k; l++) {
		for (int o = 0; o < 3; o++)
			cin >> rotation[l][o];
	}
	int answer = 1000000000;
	do {
		int rotate_graph[51][51] = {};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				rotate_graph[i][j] = graph[i][j];
		}
		for (int i = 0; i < k; i++) {
			int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, j = a[i];
			int row = rotation[j][0], col = rotation[j][1], offset = rotation[j][2];
			int startX = row - offset, startY = col - offset;
			int length = rotation[j][2] * 2 + 1, count = 0;
			while (length - 2 * count != 1) {
				int change = rotate_graph[startX][startY];
				for (int a = 0; a < 4; a++) {
					for (int b = 0; b < length-2*count-1; b++) {
						rotate_graph[startX][startY] = rotate_graph[startX+dx[a]][startY+dy[a]];
						startX += dx[a];
						startY += dy[a];
					}
				}
				rotate_graph[startX][startY+1] = change;
				startX += 1;
				startY += 1;
				count++;
			}
		}
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++)
				sum += rotate_graph[i][j];
			answer = min(answer, sum);
		}
	} while (next_permutation(a, a + k));

	cout << answer;

	return 0;
}