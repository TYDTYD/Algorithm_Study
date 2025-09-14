#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

double GetDistance(pair<int, int>& p1, pair<int, int>& p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> v(n + 1), special_City;
	unordered_set<int> special;

	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		v[i] = { x,y };
		if (s) {
			special.insert(i);
			special_City.push_back({ x,y });
		}			
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		bool aIsSpecial = (special.find(a) != special.end());
		bool bIsSpecial = (special.find(b) != special.end());
		int answer = -1;
		int dist = GetDistance(v[a], v[b]);
		if (aIsSpecial && bIsSpecial) 
			answer = t < dist ? t : dist;		
		else if (aIsSpecial) {
			auto pos = v[b];
			sort(special_City.begin(), special_City.end(), [&](pair<int, int> p1, pair<int, int> p2) {
				return GetDistance(pos, p1) < GetDistance(pos, p2);
				});
			int teleport = GetDistance(v[b], special_City[0]) + t;
			answer = teleport < dist ? teleport : dist;
		}
		else if(bIsSpecial) {
			auto pos = v[a];
			sort(special_City.begin(), special_City.end(), [&](pair<int, int> p1, pair<int, int> p2) {
				return GetDistance(pos, p1) < GetDistance(pos, p2);
				});
			int teleport = GetDistance(v[a], special_City[0]) + t;
			answer = teleport < dist ? teleport : dist;
		}
		else {
			auto pos1 = v[a];
			sort(special_City.begin(), special_City.end(), [&](pair<int, int> p1, pair<int, int> p2) {
				return GetDistance(pos1, p1) < GetDistance(pos1, p2);
				});
			int teleport = GetDistance(v[a], special_City[0]) + t;
			auto pos2 = v[b];
			sort(special_City.begin(), special_City.end(), [&](pair<int, int> p1, pair<int, int> p2) {
				return GetDistance(pos2, p1) < GetDistance(pos2, p2);
				});
			teleport += GetDistance(v[b], special_City[0]);
			answer = teleport < dist ? teleport : dist;			
		}
		cout << answer << '\n';		
	}

	return 0;
}