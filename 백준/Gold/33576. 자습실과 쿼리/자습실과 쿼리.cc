#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<long long> wall(n + 1, 0);
	vector<long long> RightWall(n + 2, 0);
	vector<long long> LeftWall(n + 1, 0);
	vector<int> student;
	for (int i = 0; i < m; i++) {
		int w, d;
		cin >> w >> d;
		wall[w] = d;
	}
	for (int i = 1; i <= n; i++) {
		if (wall[i]) {
			LeftWall[i] += wall[i];
		}
		LeftWall[i] += LeftWall[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		if (wall[i]) {
			RightWall[i] += wall[i];
		}
		RightWall[i] += RightWall[i + 1];
	}
	for (int i = 0; i < q; i++) {
		int s;
		cin >> s;
		student.push_back(s);
	}
	int L = 0;
	int R = n + 1;
	for (auto& s : student) {
		long long rCount = 0;
		if (R > s)
			rCount = RightWall[s] - RightWall[R];
		long long lCount = 0;
		if (L < s)
			lCount = LeftWall[s] - LeftWall[L];
		if (rCount > lCount) {
			L = max(L, s);
			cout << lCount << '\n';
			continue;
		}
		else if (rCount < lCount) {
			R = min(R, s);
			cout << rCount << '\n';
			continue;
		}
		else {
			int Ldist = s - 1;
			int Rdist = n - s;
			if (Ldist > Rdist) {
				R = min(R, s);
				cout << rCount << '\n';
				continue;
			}
			else {
				L = max(L, s);
				cout << lCount << '\n';
				continue;
			}
		}
	}
	return 0;
}