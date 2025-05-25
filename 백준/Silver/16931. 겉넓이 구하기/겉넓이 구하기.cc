#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int cube[101][101] = {};
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
	int max_height = -1;
	int answer = 2 * n * m;
	bool isOneWidth = false;
	bool isOneHeight = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cube[i][j];
			max_height = max(cube[i][j], max_height);
		}
	}

	if (n == 1 && m == 1) {
		cout << 6;
		return 0;
	}
	if (n == 1) {
		isOneWidth = true;
	}
	if (m == 1) {
		isOneHeight = true;
	}
		

	for (int h = 1; h <= max_height; h++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (h > cube[i][j])
					continue;
				if (isOneWidth) {
					if (j == 0 || j == m - 1)
						answer += 3;
					else
						answer += 2;
				}
				else if (isOneHeight) {
					if (i == 0 || i == n - 1)
						answer += 3;
					else
						answer += 2;
				}
				else if ((i == 0 || i == n - 1) && (j == 0 || j == m - 1))
					answer += 2;
				else if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
					answer += 1;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (h > cube[nx][ny])
						answer++;
				}
			}
		}
	}

	cout << answer;

	return 0;
}