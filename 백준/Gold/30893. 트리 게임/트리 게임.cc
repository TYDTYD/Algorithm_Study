#include <iostream>
#include <vector>
using namespace std;

bool isReached = false;
bool visited[100001] = {};

void dfs(int x, int px, vector<vector<int>>& t, int depth, int target) {
	if (visited[x])
		return;
	visited[x] = true;
	if (x == target) {
		isReached = true;
		return;
	}
	if (depth % 2 != 0 && t[x].size() > 2)
		return;
	for (auto& node : t[x]) {
		if (node != px)
			dfs(node, x, t, depth + 1, target);
	}
	
	return;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, s, e, u, v;

	cin >> n >> s >> e;

	vector<vector<int>> tree(n+1, vector<int>(0, 0));

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(s, 0, tree, 0, e);

	if (isReached)
		cout << "First";
	else
		cout << "Second";
	

	return 0;
}