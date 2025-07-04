#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double dist(double x, double y) {
	return sqrt(x * x + y * y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<double, int>> result;

	for (int i = 1; i <= n; i++) {
		double x, y, v;
		cin >> x >> y >> v;
		result.push_back({ dist(x, y) / v, i });
	}

	sort(result.begin(), result.end());

	for (const auto& robot : result) {
		cout << robot.second << '\n';
	}

	return 0;
}