#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, stick_num = 0;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
vector<vector<pair<int, int>>> sticker_seq(100, vector<pair<int, int>>(0, { 0,0 }));

void bfs(int x, int y, vector<vector<int>>& graph) {
	queue<pair<int, int>> q;
	int n = graph.size(), m = graph[0].size(), seq = -1;
	bool visited[20][20] = { false, };
	q.push({ x,y });
	sticker_seq[stick_num].push_back({ seq++,0 });
	visited[x][y] = true;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + p.first;
			int ny = dy[i] + p.second;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (visited[nx][ny] || !graph[nx][ny])
				continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
			sticker_seq[stick_num].push_back({ seq,i });
		}
		seq++;
	}
	stick_num++;
	return;
}

bool dfs(int x, int y, int d, int idx, vector<vector<int>>& notebook) {
	int num = sticker_seq[idx].size();
	vector<pair<int, int>> location;
	location.push_back({ x,y });

	for (int i = 1; i < num; i++) {
		int r = (sticker_seq[idx][i].second + d) % 4;
		int nx = dx[r] + location[sticker_seq[idx][i].first].first;
		int ny = dy[r] + location[sticker_seq[idx][i].first].second;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			return false;
		if (notebook[nx][ny])
			return false;
		location.push_back({ nx,ny });
	}

	for (const auto& l : location)
		notebook[l.first][l.second] = 1;

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, answer = 0;

	cin >> n >> m >> k;
	vector<vector<int>> notebook(n, vector<int>(m, 0));
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		vector<vector<int>> sticker(a, vector<int>(b, 0));
		int startX, startY;
		bool pass = false;
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < b; k++) {
				cin >> sticker[j][k];
				if (!pass && sticker[j][k] == 1) {
					startX = j;
					startY = k;
					pass = true;
				}
			}
		}
		bfs(startX, startY, sticker);
	}
	
	bool isUsed[100] = { false, };

	for (int i = 0; i < k; i++) {
		for (int d = 0; d < 4; d++) {
			if (isUsed[i])
				break;
			for (int x = 0; x < n; x++) {
				if (isUsed[i])
					break;
				for (int y = 0; y < m; y++) {
					if (notebook[x][y] == 0 && dfs(x, y, d, i, notebook)) {
						answer += sticker_seq[i].size();
						isUsed[i] = true;
						break;
					}
				}
			}
		}
	}

	cout << answer;

	return 0;
}