#include <iostream>
#include <vector>
using namespace std;

int n;

void move(int d, int board[20][20]) {
	if (d == 0) {
		for (int i = n - 1; i >= 0; i--) {
			int tilted[21] = {};
			int idx = 0;
			for (int j = n - 1; j >= 0; j--) {
				if (board[j][i] == 0)
					continue;
				if (tilted[idx] == 0)
					tilted[idx] = board[j][i];
				else if (tilted[idx] == board[j][i])
					tilted[idx++] *= 2;
				else
					tilted[++idx] = board[j][i];
			}
			for (int j = n - 1; j >= 0; j--)
				board[j][i] = tilted[j];
		}
	}
	else if (d == 1) {
		for (int i = n - 1; i >= 0; i--) {
			int tilted[21] = {};
			int idx = 0;
			for (int j = n - 1; j >= 0; j--) {
				if (board[i][j] == 0)
					continue;
				if (tilted[idx] == 0)
					tilted[idx] = board[i][j];
				else if (tilted[idx] == board[i][j])
					tilted[idx++] *= 2;
				else
					tilted[++idx] = board[i][j];
			}
			for (int j = n - 1; j >= 0; j--)
				board[i][j] = tilted[j];
		}
	}
	else if (d == 2) {
		for (int i = 0; i < n; i++) {
			int tilted[21] = {};
			int idx = 0;
			for (int j = 0; j < n; j++) {
				if (board[j][i] == 0)
					continue;
				if (tilted[idx] == 0)
					tilted[idx] = board[j][i];
				else if (tilted[idx] == board[j][i])
					tilted[idx++] *= 2;
				else
					tilted[++idx] = board[j][i];
			}
			for (int j = 0; j < n; j++)
				board[j][i] = tilted[j];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			int tilted[21] = {};
			int idx = 0;
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0)
					continue;
				if (tilted[idx] == 0)
					tilted[idx] = board[i][j];
				else if (tilted[idx] == board[i][j])
					tilted[idx++] *= 2;
				else
					tilted[++idx] = board[i][j];
			}
			for (int j = 0; j < n; j++)
				board[i][j] = tilted[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int board[20][20], board_copy[20][20], answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			board_copy[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 1 << 2 * 5; i++) {
		int brute = i;
		for (int j = 0; j < 5; j++) {
			int d = brute % 4;
			brute /= 4;
			move(d, board_copy);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board_copy[i][j] != 0)
					answer = max(answer, board_copy[i][j]);
				board_copy[i][j] = board[i][j];
			}
		}
	}

	cout << answer;

	return 0;
}