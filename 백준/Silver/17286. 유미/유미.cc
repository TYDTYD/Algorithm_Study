#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Pos {
	int x, y;
	Pos(int _x, int _y) : x(_x), y(_y) {}
};

double GetDistance(Pos& pos1, Pos& pos2) {
	return sqrt((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	Pos cat(x, y);
	vector<Pos> v;
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(Pos(x, y));
	}

	int answer = 1e9;

	for (int i = 0; i < 3; i++) {
		int result = 0;
		for(int j = 0; j < 3; j++) {
			if (i == j) 
				continue;
			for(int k = 0; k < 3; k++) {
				if(k == i || k == j) 
					continue;
				result = GetDistance(cat, v[i]) + GetDistance(v[i], v[j]) + GetDistance(v[j], v[k]);
			}			
			answer = min(answer, result);
			result = 0;
		}
	}

	cout << answer;
	return 0;
}