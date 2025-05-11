#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

typedef pair<int, int> p;

void isEqual(p& p1, p& p2, p& p3, p& p4, unordered_set<int>& result) {
	int dist1 = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
	int dist2 = (p1.first - p3.first) * (p1.first - p3.first) + (p1.second - p3.second) * (p1.second - p3.second);
	int dist3 = (p1.first - p4.first) * (p1.first - p4.first) + (p1.second - p4.second) * (p1.second - p4.second);
	result.insert(dist1);
	result.insert(dist2);
	result.insert(dist3);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		bool possible = true;
		vector<p> v(4);
		unordered_set<int> result;

		for (int i = 0; i < 4; i++) {
			int x, y;
			cin >> x >> y;
			v[i] = { x,y };
		}

		for (int i = 0; i < 4; i++)
			isEqual(v[i % 4], v[(i + 1) % 4], v[(i + 2) % 4], v[(i + 3) % 4], result);

		possible = (result.size() == 2);

		cout << possible << '\n';
	}
	return 0;
}