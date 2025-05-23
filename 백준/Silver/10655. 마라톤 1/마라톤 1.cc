#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int GetDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int result = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
		result = (i > 0) ? result += GetDist(v[i].first, v[i].second, v[i - 1].first, v[i - 1].second) : result;
	}
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 1; i < n - 1; i++) {
		int dist1 = GetDist(v[i - 1].first, v[i - 1].second, v[i].first, v[i].second);
		int dist2 = GetDist(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
		int shortcut = GetDist(v[i - 1].first, v[i - 1].second, v[i + 1].first, v[i + 1].second);
		pq.push(result - (dist1 + dist2) + shortcut);;
	}

	cout << pq.top();

	return 0;
}