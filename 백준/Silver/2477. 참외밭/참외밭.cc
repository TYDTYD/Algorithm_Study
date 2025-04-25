#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
#include <unordered_map>
using namespace std;

int main() {
	int k;
	cin >> k;
	int width[3], heigth[3];
	int w_idx = 0, h_idx = 0;
	queue<array<int, 2>> q;
	unordered_map<int,int> m;

	for (int i = 0; i < 6; i++) {
		int dir, length;
		cin >> dir >> length;
		q.push({ dir,length });
		if (dir == 1 || dir == 2)
			width[w_idx++] = length;
		else
			heigth[h_idx++] = length;
		m[dir]++;
	}

	int square = (*max_element(heigth, heigth + 3)) * (*max_element(width, width + 3));
	int minus = 1, seq = 0;
	while (!q.empty()) {
		if (m[q.front()[0]] != 2) {
			if (seq != 4) {
				seq = 0;
				q.push(q.front());
				q.pop();
				minus = 1;
			}
		}
		else {
			if (seq == 1 || seq == 2)
				minus *= q.front()[1];
			if (seq == 3)
				break;
			q.push(q.front());
			q.pop();
			seq++;
		}
	}
	square -= minus;
	cout << square * k;
	return 0;
}