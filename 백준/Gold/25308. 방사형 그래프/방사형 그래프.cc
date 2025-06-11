#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[8], a[8];
int answer = 0;
const double PIE = acos(-1);

double ccw(pair<double, double>& x, pair<double, double>& y, pair<double, double>& z) {
	double result = (y.first - x.first) * (z.second - x.second) - (y.second - x.second) * (z.first - x.first);
	return result;
}

double degreeToRad(int degree) {
	return degree * (PIE / 180);
}

pair<double, double> pos(double r, int i) {
	return make_pair(r * cos(degreeToRad(i * 45)), r * sin(degreeToRad(i * 45)));
}

void solve() {
	vector<pair<double, double>> posList;
	for (int i = 0; i < 8; i++)
		posList.push_back(pos(arr[i], i));

	bool plag = true;
	for (int i = 0; i < 8; i++) {
		if (i == 0) {
			if (ccw(posList[7], posList[i], posList[i + 1]) <= 0) {
				plag = false;
				break;
			}
		}
		else if (i == 7) {
			if (ccw(posList[i-1], posList[i] ,posList[0]) <= 0) {
				plag = false;
				break;
			}
		}
		else {
			if (ccw(posList[i - 1], posList[i], posList[i + 1]) <= 0) {
				plag = false;
				break;
			}
		}
	}

	if (plag)
		answer++;
}

void backTracking(int c, bool visited[]) {
	if (c == 8) {
		solve();
		return;
	}

	for (int i = 0; i < 8; i++) {
		if (!visited[i]) {
			arr[c] = a[i];
			visited[i] = true;
			backTracking(c + 1, visited);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool visited[8] = {};

	for (int i = 0; i < 8; i++)
		cin >> a[i];

	backTracking(0, visited);

	cout << answer;

	return 0;
}