#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r;
	cin >> n >> r;
	vector<pair<int, int>> pos;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pos.push_back({ x,y });
	}
	pair<int, int> answer = { 0,0 };
	int max_count = 0;
	for (int i = -100; i <= 100; i++) {
		for (int j = -100; j <= 100; j++) {
			int count = 0;
			for (const auto& p : pos) {
				if ((i - p.first) * (i - p.first) + (j - p.second) * (j - p.second) <= r*r)
					count++;
			}
			if (count > max_count) {
				max_count = count;
				answer = { i,j };
			}
		}
	}

	cout << answer.first << " " << answer.second;

	return 0;
}