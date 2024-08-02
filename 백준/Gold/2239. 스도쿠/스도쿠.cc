using namespace std;
#include <iostream>
#include <vector>
#include <string>

vector<pair<int, int>> points;

int a[9][9];
int cnt = 0;
int answer=0;

bool check(pair<int, int> p)
{
	int square_x = p.first / 3;
	int square_y = p.second / 3;
	for (int i = 0; i < 9; i++)
	{
		if (a[p.first][i] == a[p.first][p.second] && i != p.second)
			return false;
		if (a[i][p.second] == a[p.first][p.second] && i != p.first)
			return false;
	}

	for (int i = 3 * square_x; i < 3 * square_x + 3; i++)
		for (int j = 3 * square_y; j < 3 * square_y + 3; j++)
		{
			if (a[i][j] == a[p.first][p.second] && i != p.first && j != p.second)
			{
				return false;
			}
		}
	return true;
}

void solve(int c) {
	if (c == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
		exit(0);
		return;
	}

	for (int k = 1; k < 10; k++) {
		a[points[c].first][points[c].second] = k;
		if (check(points[c]))
			solve(c + 1);
		a[points[c].first][points[c].second] = 0;
	}

	return;
}

int main() {
	pair<int, int> point;
	string input;
	for (int i = 0; i < 9; i++) {
		cin >> input;
		for (int j = 0; j < 9; j++)
		{
			a[i][j] = (int)(input[j] - '0');
			if (a[i][j] == 0)
			{
				cnt++;
				point.first = i;
				point.second = j;
				points.push_back(point);
			}
		}

	}

	solve(0);
	return 0;
}