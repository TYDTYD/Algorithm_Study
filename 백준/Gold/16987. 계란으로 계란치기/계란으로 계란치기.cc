#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void solve(int c, int n, int result, vector<pair<int,int>>& e) {
	if (n == c) {
		answer = max(answer, result);
		return;
	}
	answer = max(answer, result);
	for (int i = 0; i < n; i++) {
		if (i == c)
			continue;
		if (e[i].first > 0) {
			e[c].first -= e[i].second;
			e[i].first -= e[c].second;
			if (e[c].first <= 0)
				result++;
			if (e[i].first <= 0)
				result++;
			int idx = c + 1;
			while (n != idx && e[idx].first <= 0)
				idx++;
			solve(idx, n, result, e);
			if (e[c].first <= 0)
				result--;
			if (e[i].first <= 0)
				result--;
			e[c].first += e[i].second;
			e[i].first += e[c].second;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> egg(n);

	for (int i = 0; i < n; i++) {
		int s, w;
		cin >> s >> w;
		egg[i] = make_pair(s, w);
	}

	solve(0, n, 0, egg);

	cout << answer;

	return 0;
}