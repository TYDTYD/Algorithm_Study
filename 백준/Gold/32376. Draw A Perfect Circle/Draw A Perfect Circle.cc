#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

double dist(double x,double y) {
	return sqrt(x * x + y * y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double n, k;
	cin >> n >> k;
	vector<double> v;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		v.emplace_back(dist(x, y));
	}
	sort(v.begin(), v.end());
	int answer = 0;
	for (vector<double>::iterator it = v.begin(); it != v.end(); it++) {
		
		int result = upper_bound(v.begin(), v.end(), *it + k)
			- lower_bound(v.begin(), v.end(), *it);
		answer = max(answer, result);
	}
	cout.precision(10);
	cout << fixed;
	cout << answer * (100 / n);
	return 0;
}