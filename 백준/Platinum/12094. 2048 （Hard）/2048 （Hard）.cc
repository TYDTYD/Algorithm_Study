#include <iostream>
#include <vector>
using namespace std;

int n;
int now_num, answer = 0, board_max = 0, board[20][20], board_copy[20][20];
bool move(int d, int board[20][20]) {
	bool change = false;
	now_num = board_max;
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
			for (int j = n - 1; j >= 0; j--) {
				if (tilted[n - 1 - j] != board[j][i])
					change = true;
				now_num = max(now_num, tilted[j]);
				board[j][i] = tilted[n - 1 - j];
			}
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
			for (int j = n - 1; j >= 0; j--) {
				if (tilted[n - 1 - j] != board[i][j])
					change = true;
				now_num = max(now_num, tilted[j]);
				board[i][j] = tilted[n - 1 - j];
			}
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
			for (int j = 0; j < n; j++) {
				if (tilted[j] != board[j][i])
					change = true;
				now_num = max(now_num, tilted[j]);
				board[j][i] = tilted[j];
			}
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
			for (int j = 0; j < n; j++) {
				if (tilted[j] != board[i][j])
					change = true;
				now_num = max(now_num, tilted[j]);
				board[i][j] = tilted[j];
			}
		}
	}
	return change;
}


void dfs(int depth, int b[20][20]) {
	if (depth == 10) {
		answer = max(answer, now_num);
		return;
	}
	int tmp_board[20][20];
	for (int i = 0; i < 4; i++) {
		if (answer >= (now_num * (1 << (10 - depth))))
			continue;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				tmp_board[i][j] = b[i][j];
		}
		if (!move(i, b))
			continue;
		dfs(depth + 1, b);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				b[i][j] = tmp_board[i][j];
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int max_idx;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			board_copy[i][j] = board[i][j];
			board_max = max(board_max, board[i][j]);
		}
	}

	now_num = board_max;
	answer = board_max;
	dfs(0, board_copy);

	/*
	for (int i = 0; i < 1 << 2 * 10; i++) {
		int brute = i;
		now_num = board_max;
		for (int j = 0; j < 10; j++) {
			if (answer >= (now_num * (1 << (10 - j))))
				break;
			int d = brute % 4;
			brute /= 4;
			if (!move(d, j + 1, board_copy))
				break;
		}
		answer = max(answer, now_num);
		
	}*/
	cout << answer;

	return 0;
}