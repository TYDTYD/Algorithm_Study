#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double DegreeToRadian(double& deg) {
	const double pie = acos(-1);
	return deg *= (pie / 180);
}

int cross(double x1, double y1, double x2, double y2) {
	double result = (x1 * y2 - y1 * x2);
	if (result > 0)
		return 1;
	else if (result < 0)
		return -1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	double r = 1000;
	pair<double, double> p1, p2;
	vector<pair<double, double>> lines(n);
	vector < pair<pair<double, double>, pair<double, double>>> pos;

	for (int i = 0; i < n; i++) {
		double angleX, angleY;
		cin >> angleX >> angleY;
		lines[i] = { angleX / 10,angleY / 10 };
		double rad1 = DegreeToRadian(lines[i].first);
		double rad2 = DegreeToRadian(lines[i].second);
		
		double firstX = r * cos(rad1);
		double firstY = r * sin(rad1);

		double secondX = r * cos(rad2);
		double secondY = r * sin(rad2);

		lines[i].first = secondX - firstX;
		lines[i].second = secondY - firstY;

		pos.push_back({ {firstX,firstY},{secondX,secondY} });
	}

	double angle1, d1;
	cin >> angle1 >> d1;
	double angle2, d2;
	cin >> angle2 >> d2;
	p1 = { angle1/10,d1 };
	p2 = { angle2/10,d2 };
	double rad1 = DegreeToRadian(p1.first);
	p1.first = p1.second * cos(rad1);
	p1.second = p1.second * sin(rad1);

	double rad2 = DegreeToRadian(p2.first);
	p2.first = p2.second * cos(rad2);
	p2.second = p2.second * sin(rad2);

	int count = 0;

	for (int i = 0; i < n; i++) {
		pair<double, double> first_p1 = { p1.first - pos[i].first.first,p1.second - pos[i].first.second };
		pair<double, double> p1_second = { pos[i].second.first - p1.first, pos[i].second.second - p1.second };

		pair<double, double> first_p2 = { p2.first - pos[i].first.first,p2.second - pos[i].first.second };
		pair<double, double> p2_second = { pos[i].second.first - p2.first, pos[i].second.second - p2.second };

		if (cross(first_p1.first, first_p1.second, p1_second.first, p1_second.second) * cross(first_p2.first, first_p2.second, p2_second.first, p2_second.second) == -1)
			count++;
	}

	if (count % 2 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}