#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int n, m;

void rotate(int x, int y, int d, vector<vector<int>>& o) {
	int nx = x, ny = y;
	d %= 4;
	while (true) {
		nx += dx[d];
		ny += dy[d];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || o[nx][ny] == 6)
			break;
		if (o[nx][ny] > 0 && o[nx][ny] < 6)
			continue;
		o[nx][ny] = 7;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int answer = n*m, result = 0;
	vector<vector<int>> office(n, vector<int>(m, 0));
	vector<pair<int,int>> cctv;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6)
				cctv.push_back({ i,j });
		}
	}
	int c = 1 << 2 * cctv.size();
	for (int i = 0; i < c; i++) {
		int brute = i;
		for (int j = 0; j < cctv.size(); j++) {
			int direction = brute % 4;
			if(office[cctv[j].first][cctv[j].second]==1)
				rotate(cctv[j].first, cctv[j].second, direction, office);
			else if (office[cctv[j].first][cctv[j].second] == 2) {
				rotate(cctv[j].first, cctv[j].second, direction, office);
				rotate(cctv[j].first, cctv[j].second, direction+2, office);
			}
			else if (office[cctv[j].first][cctv[j].second] == 3) {
				rotate(cctv[j].first, cctv[j].second, direction, office);
				rotate(cctv[j].first, cctv[j].second, direction+1, office);
			}
			else if (office[cctv[j].first][cctv[j].second] == 4) {
				rotate(cctv[j].first, cctv[j].second, direction, office);
				rotate(cctv[j].first, cctv[j].second, direction+1, office);
				rotate(cctv[j].first, cctv[j].second, direction+2, office);
			}
			else if (office[cctv[j].first][cctv[j].second] == 5) {
				rotate(cctv[j].first, cctv[j].second, direction, office);
				rotate(cctv[j].first, cctv[j].second, direction+1, office);
				rotate(cctv[j].first, cctv[j].second, direction+2, office);
				rotate(cctv[j].first, cctv[j].second, direction+3, office);
			}
			brute /= 4;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (office[i][j] == 7)
					office[i][j] = 0;
				else if (office[i][j] == 0)
					result++;
			}
		}
		if (answer > result)
			answer = result;
		result = 0;
	}

	cout << answer;
	
	return 0;
}