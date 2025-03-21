#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> pos(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pos[i].first = x;
		pos[i].second = y;
	}
	sort(pos.begin(), pos.end());
	for (const auto& p : pos)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}