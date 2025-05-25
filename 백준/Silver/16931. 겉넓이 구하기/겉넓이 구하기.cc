#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int cube[101][101] = {};
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
	int max_height = -1;
	int answer = 2 * n * m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cube[i][j];
			max_height = max(cube[i][j], max_height);
		}
	}

	for (int h = 1; h <= max_height; h++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (h > cube[i][j])
					continue;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
						answer++;
						continue;
					}
					if (h > cube[nx][ny])
						answer++;
				}
			}
		}
	}

	cout << answer;

	return 0;
}