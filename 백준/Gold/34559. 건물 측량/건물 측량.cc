#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);

	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) {
			if (s[j] == '0')
				graph[i].push_back(0);
			else
				graph[i].push_back(1);
		}
	}

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };	
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[0][0] = true;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
				continue;
			if (visited[nx][ny])
				continue;
			if(graph[nx][ny] == 1)
				continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (!visited[i][j])
				graph[i][j] = 1;
		}
	}
	vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + graph[i][j];
		}
	}

	int query;
	cin >> query;
	for (int i = 0; i < query; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;		
		int answer = sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
		if (answer == 0)
			cout << "Yes\n";
		else
			cout << "No " << answer << '\n';
	}

	return 0;
}