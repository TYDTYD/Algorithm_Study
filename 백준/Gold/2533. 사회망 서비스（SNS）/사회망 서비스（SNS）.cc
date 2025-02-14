#include <iostream>
#include <vector>
using namespace std;

int dp[1000001][2];
bool visited[1000001];

void dfs(int x,vector<vector<int>>& graph) {
	visited[x] = true;
	dp[x][1] = 1;
	for (const auto& c : graph[x]) {
		if (visited[c])
			continue;
		dfs(c, graph);
		dp[x][0] += dp[c][1];
		dp[x][1] += min(dp[c][0], dp[c][1]);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> tree(n + 1, vector<int>());
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].emplace_back(v);
		tree[v].emplace_back(u);
	}
	dfs(1, tree);
	int answer = min(dp[1][0], dp[1][1]);
	cout << answer;
	return 0;
}