#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool visited[1001][1001];

int find_parent(int n, int x, int y, int init_x, int init_y, bool first, vector<vector<int>>& v) {
	if (!first) {
		if (init_x == x && init_y == y)
			return n;
	}
	if (n == v[x][y])
		return n;
	visited[x][y] = true;
	return v[x][y] = find_parent(v[x][y], v[x][y] / 1000, v[x][y] % 1000, init_x, init_y, false, v);
}

void merge(int x, int y, vector<vector<int>>& v) {
	int parent_x = find_parent(x, x / 1000, x % 1000, x / 1000, x % 1000, true, v);
	int parent_y = find_parent(y, y / 1000, y % 1000, y / 1000, y % 1000, true, v);
	if (parent_x != parent_y)
		v[parent_x / 1000][parent_x % 1000] = parent_y;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			graph[i][j] = i * 1000 + j;
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'U')
				merge(graph[i][j], graph[i - 1][j], graph);
			else if (s[j] == 'D')
				merge(graph[i][j], graph[i + 1][j], graph);
			else if (s[j] == 'L')
				merge(graph[i][j], graph[i][j - 1], graph);
			else if (s[j] == 'R')
				merge(graph[i][j], graph[i][j + 1], graph);
		}
	}
	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			s.insert(find_parent(graph[i][j], graph[i][j] / 1000, graph[i][j] % 1000, graph[i][j] / 1000, graph[i][j] % 1000, true, graph));
		}
	}
	cout << s.size();
	return 0;
}