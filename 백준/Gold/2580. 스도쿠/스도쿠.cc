using namespace std;
#include <iostream>
#include <vector>

vector<pair<int, int>> points;

// 가로 줄 들어갈 수 있는지
bool visited1[9][9];

// 세로 줄 들어갈 수 있는지
bool visited2[9][9];

// 정사각형 들어갈 수 있는지
bool visited3[9][9];

int a[9][9];
int cnt = 0;

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
			if (a[i][j] == a[p.first][p.second])
			{
				if (i != p.first && j != p.second)
					return false;
			}
		}
	return true;
}

bool check1(pair<int,int> p, int k) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!visited1[p.first][k-1] && !visited2[p.second][k - 1]) {
				if (i < 3) {
					if (j < 3) {
						if (!visited3[0][k - 1])
							return true;
					}
					else if (j < 6) {
						if (!visited3[1][k - 1])
							return true;
					}
					else {
						if (!visited3[2][k - 1])
							return true;
					}
				}
				else if (i < 6) {
					if (j < 3) {
						if (!visited3[3][k - 1])
							return true;
					}
					else if (j < 6) {
						if (!visited3[4][k - 1])
							return true;
					}
					else {
						if (!visited3[5][k - 1])
							return true;
					}
				}
				else {
					if (j < 3) {
						if (!visited3[6][k - 1])
							return true;
					}
					else if (j < 6) {
						if (!visited3[7][k - 1])
							return true;
					}
					else {
						if (!visited3[8][k - 1])
							return true;
					}
				}
			}
		}
	}
	return false;
}

void solve(int c) {
	if (c == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << a[i][j] << " ";
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
	}

	a[points[c].first][points[c].second] = 0;
	return;

}

int main() {
	pair<int, int> point;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				cnt++;
				point.first = i;
				point.second = j;
				points.push_back(point);
				continue;
			}
			if (i < 3) {
				if (j < 3)
					visited3[0][a[i][j] - 1] = true;
				else if (j < 6)
					visited3[1][a[i][j] - 1] = true;
				else
					visited3[2][a[i][j] - 1] = true;
			}
			else if (i < 6) {
				if (j < 3)
					visited3[3][a[i][j] - 1] = true;
				else if (j < 6)
					visited3[4][a[i][j] - 1] = true;
				else
					visited3[5][a[i][j] - 1] = true;
			}
			else {
				if (j < 3)
					visited3[6][a[i][j] - 1] = true;
				else if (j < 6)
					visited3[7][a[i][j] - 1] = true;
				else
					visited3[8][a[i][j] - 1] = true;
			}
		}
	}
	/*
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				cnt++;
				continue;
			}
			visited1[i][a[i][j] - 1] = true;
			visited2[j][a[i][j] - 1] = true;
			if (i < 3) {
				if (j < 3)
					visited3[0][a[i][j] - 1] = true;
				else if (j < 6)
					visited3[1][a[i][j] - 1] = true;
				else
					visited3[2][a[i][j] - 1] = true;
			}
			else if (i < 6) {
				if (j < 3)
					visited3[3][a[i][j] - 1] = true;
				else if (j < 6)
					visited3[4][a[i][j] - 1] = true;
				else
					visited3[5][a[i][j] - 1] = true;
			}
			else {
				if (j < 3)
					visited3[6][a[i][j] - 1] = true;
				else if (j < 6)
					visited3[7][a[i][j] - 1] = true;
				else
					visited3[8][a[i][j] - 1] = true;
			}
		}
	}*/

	solve(0);
}