#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int find_parent(int x, vector<int>& v) {
	if (v[x] == x)
		return x;
	return v[x] = find_parent(v[x], v);
}

void merge(int x,int y, vector<int>& v) {
	int parent_x = find_parent(x, v);
	int parent_y = find_parent(y, v);
	if (parent_x != parent_y) {
		v[parent_y] = parent_x;
	}
}

bool dfs(int x,int before_x, bool visited[501], vector<vector<int>>& graph) {
	if (visited[x])
		return false;
	visited[x] = true;
	for (const auto& n : graph[x]) {
		if (n == before_x)
			continue;
		if (!dfs(n, x, visited, graph))
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, t = 1;
	while (true) {
		cin >> n >> m;
		if (!n && !m)
			break;
		vector<int> graph;
		for (int i = 0; i <= n; i++)
			graph.emplace_back(i);
		vector<vector<int>> tree(n + 1, vector<int>());
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			tree[x].emplace_back(y);
			tree[y].emplace_back(x);
			merge(x, y, graph);
		}
		unordered_set<int> c;
		for (int i = 1; i <= n; i++)
			c.insert(find_parent(i, graph));
		int tree_count = 0;
		bool visited[501] = {};
		for (const auto& parent : c) {
			if (dfs(parent, 0, visited, tree))
				tree_count++;
		}
		cout << "Case " << t++ << ": ";
		if (tree_count == 0)
			cout << "No trees." << '\n';
		else if (tree_count == 1)
			cout << "There is one tree." << '\n';
		else if (tree_count > 1)
			cout << "A forest of " << tree_count << " trees." << '\n';
	}
	
	return 0;
}