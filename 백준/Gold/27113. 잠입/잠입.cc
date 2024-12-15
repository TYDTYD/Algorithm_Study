#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, path = 1;
	bool flag = true;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int x;
		vector<pair<int, char>> v;
		v.clear();
		cin >> x;
		for (int j = 0; j < x; j++) {
			int c;
			char dir;
			cin >> c >> dir;
			v.emplace_back(make_pair(c, dir));
		}
		if (x == 1) {
			if (v.front().second == 'R') {
				// R P
				if (path >= v.front().first)
					flag = false;
			}
			else {
				// L P
				if (path > v.front().first)
					continue;
				path = v.front().first + 1;
			}
		}
		else if(x == 2) {
			// L 과 R이 존재할 때
			if (v.front().second != v.back().second) {
				// R L
				if (v.front().second == 'R') {
					// P R L
					if (path < v.front().first)
						continue;
					// R L P
					else if (path > v.back().first)
						continue;
					// R P L
					path = v.back().first + 1;
				}
				else {
					// L R
					if (v.back().first - v.front().first == 1)
						flag = false;
					// P L R
					else if (path <= v.front().first)
						path = v.front().first + 1;
					// L R P
					else if (path >= v.back().first)
						flag = false;
				}
			}
			// L 2개 or R 2개
			else {
				if (v.front().second == 'R') {
					if (path >= v.front().first)
						flag = false;
				}
				else {
					if (path <= v.back().first)
						path = v.back().first + 1;
				}
			}
		}

		if (path > m)
			flag = false;
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}