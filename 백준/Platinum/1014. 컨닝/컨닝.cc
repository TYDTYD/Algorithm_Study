#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	string classroom[11];
	while (T--) {
		int n, m, answer = 0;
		cin >> n >> m;
		vector<pair<int, int>> seat;
		int broken[11] = {};
		int desk = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			classroom[i] = s;
			int bit = 1;
			for (int j = 0; j < m; j++) {
				if (s[j] == 'x') {
					broken[i] += bit;
					desk++;
				}
				bit <<= 1;
			}
		}
		if (m == 1) {
			cout << n - desk << '\n';
			continue;
		}

		int student[11][1025];

		for (int i = 0; i < 11; i++)
			fill(student[i], student[i] + (1 << m) + 1, 0);
		for (int i = 0; i < (1 << m); i++) {
			int near = 3;
			bool p = true;
			for(int j=0; j<m-1; j++) {
				if ((near & i) == near) {
					p = false;
					break;
				}
				near <<= 1;
			}
			if (p) {
				int cnt = 0;
				for(int j=0; j<m; j++) {
					if (((1 << j) & i) != 0)
						cnt++;
				}
				seat.emplace_back(make_pair(i, cnt));
			}
		}

		for (int i = 0; i < n; i++) {
			for (const auto& bit:seat) {
				if (bit.first & broken[i])
					continue;
				for (const auto& front:seat) {
					bool p = true;
					for (int i = 0; i < m; i++) {
						if ((1 << i) & front.first) {
							if (i > 0 && ((1 << (i - 1)) & bit.first)) {
								p = false;
								break;
							}
							if ((1 << (i + 1) & bit.first)) {
								p = false;
								break;
							}
						}
					}
					if (p) {
						student[i+1][bit.first] = max(student[i+1][bit.first], student[i][front.first] + bit.second);
						answer = max(answer, student[i + 1][bit.first]);
					}
				}
			}
		}

		cout << answer << '\n';
	}
	return 0;
}