#include <iostream>
#include <vector>
using namespace std;

typedef pair<long long, long long> pl;

vector<pl> v;

double dot(pl u, pl v) {
	return u.first * v.first + u.second * v.second;
}

bool check(int a,int b,int c) {
	pl ab = { v[b].first - v[a].first, v[b].second - v[a].second };
	pl ac = { v[c].first - v[a].first, v[c].second - v[a].second };
	if (dot(ab, ac) == 0) 
		return true;

	pl ba = { v[a].first - v[b].first, v[a].second - v[b].second };
	pl bc = { v[c].first - v[b].first, v[c].second - v[b].second };
	if (dot(ba, bc) == 0) 
		return true;

	pl ca = { v[a].first - v[c].first, v[a].second - v[c].second };
	pl cb = { v[b].first - v[c].first, v[b].second - v[c].second };
	if (dot(ca, cb) == 0)
		return true;
	return false;
}

int main() {
	int n, answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j+ 1; k < n; k++) {
				if (check(i, j, k))
					answer++;
			}
		}
	}

	cout << answer;

	return 0;
}