#include <iostream>
#include <stack>
using namespace std;

bool isUsed[9] = {};
int player[9] = {}, answer = 0, c, inning[50][10] = {};
void solve(int n) {
	if (n == 9) {
		int number = 0, score = 0;
		for (int i = 0; i < c; i++) {
			stack<int> s;
			int out = 0, sum = 0;
			while (out < 3) {
				for (int j = number; j < 9; j++) {
					if (inning[i][player[j]] == 0) {
						out++;
						if (out == 3) {
							number = j + 1;
							break;
						}
					}
					else
						s.push(inning[i][player[j]]);
				}
				if (out != 3)
					number = 0;
			}
			while (!s.empty()) {
				sum += s.top();
				s.pop();
				if (sum >= 4) {
					score += s.size() + 1;
					break;
				}
			}
		}
		answer = max(answer, score);

		return;
	}
	if (n == 3) {
		player[n] = 0;
		solve(n + 1);
	}

	for (int i = 0; i < 9; i++) {
		if (!isUsed[i]) {
			isUsed[i] = true;
			player[n] = i;
			solve(n + 1);
			isUsed[i] = false;
		}
	}
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	isUsed[0] = true;
	player[3] = 0;
	cin >> c;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < 9; j++)
			cin >> inning[i][j];
	}

	solve(0);

	cout << answer;

	return 0;
}