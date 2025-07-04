#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double dist(double a, double b, double c, double d) {
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> graph(n);
	pair<int, int> professor;
	pair<int, int> student;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (num == 5)
				professor = { i,j };
			else if (num == 2)
				student = { i,j };
			graph[i].push_back(num);
		}
	}

	if (dist(professor.first, professor.second, student.first, student.second) < 5) {
		cout << 0;
		return 0;
	}

	int studentCount = 0;
	int startX = min(professor.first, student.first);
	int endX = max(professor.first, student.first);
	int startY = min(professor.second, student.second);
	int endY = max(professor.second, student.second);

	for (int i = startX; i <= endX; i++) {
		for (int j = startY; j <= endY; j++) {
			if (graph[i][j] == 1)
				studentCount++;
		}
	}

	if (studentCount >= 3)
		cout << 1;
	else
		cout << 0;

	return 0;
}