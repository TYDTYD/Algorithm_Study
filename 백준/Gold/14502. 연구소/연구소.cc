#include <iostream>
#include <vector>
using namespace std;

bool isused[10][10], visited[10][10];
int graph[10][10], result = 0, answer = 0, area = 0;
vector<pair<int,int>> virus;

void seeking(int x, int y, int n, int m) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return;
	if (graph[x][y] == 1)
		return;
	if (visited[x][y])
		return;
	visited[x][y] = true;

	if(graph[x][y]!=2)
		result += 1;
	seeking(x + 1, y, n, m);
	seeking(x - 1, y, n, m);
	seeking(x, y + 1, n, m);
	seeking(x, y - 1, n, m);
	return;
}

void backTracking(int n, int m, int k) {
	if (k==3) {
		for (const auto& v : virus)
			seeking(v.first, v.second, n, m);
		for (int i = 0; i < 10; i++)
			fill(visited[i], visited[i] + 10, false);
		answer = max(area - result,answer);
		result = 0;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				if (!isused[i][j]) {
					isused[i][j] = true;
					graph[i][j] = 1;
					backTracking(n, m, k + 1);
					isused[i][j] = false;
					graph[i][j] = 0;
				}
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2)
				virus.push_back({ i,j });
			else if (graph[i][j] == 0)
				area += 1;
		}
	}

	area -= 3;

	backTracking(n, m, 0);

	cout << answer;

	return 0;
}