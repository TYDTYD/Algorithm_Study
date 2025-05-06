#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

int bfs(int x, vector<vector<int>>& graph, unordered_set<int>& c) {
	queue<pair<int, int>> q;
	bool visited[3001] = {};
	int dist = 0;
	visited[x] = true;
	q.push({ x,0 });
	
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (c.find(p.first) != c.end()) {
			dist = p.second;
			break;
		}
		for (const auto& node : graph[p.first]) {
			if (visited[node])
				continue;
			q.push({ node,p.second + 1 });
			visited[node] = true;
		}
	}
	return dist;
}

bool dfsR(int x, int parent, vector<vector<int>>& graph, unordered_set<int>& s, int target) {
	if (target == x)
		return true;

	for (const auto& station : graph[x]) {
		if (station == parent)
			continue;
		s.insert(station);
		if (dfsR(station, x, graph, s, target))
			return true;
		s.erase(station);
	}
	return false;
}

void dfs(int x, int parent, vector<vector<int>>& graph, bool visited[3001], unordered_set<int>& s) {
	if (s.find(x) != s.end())
		return;
	if (visited[x]) {
		s.insert(x);
		dfsR(x, parent, graph, s, parent);
		return;
	}
	visited[x] = true;

	for (const auto& station : graph[x]) {
		if (station == parent)
			continue;
		dfs(station, x, graph, visited, s);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	bool visited[3001] = {};
	unordered_set<int> cycle;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1, 0, v, visited, cycle);
	
	for (int i = 1; i <= n; i++) {
		if (cycle.find(i) != cycle.end())
			cout << 0 << ' ';
		else
			cout << bfs(i, v, cycle) << ' ';
	}

	return 0;
}