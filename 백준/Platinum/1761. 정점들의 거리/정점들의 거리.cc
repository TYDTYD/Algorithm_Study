#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> neighbor[100001];
int parent[100001][20];
int dist[100001][20];
int depth[100001];
int cost[100001];
int answer = 0;

void makeTree(int n, int d, int p, int c) {
	depth[n] = d;
	if (n != 1) {
		parent[n][0] = p;
		dist[n][0] = c;
		int idx = parent[n][0];
		int acs = 1;
		int num = 1;
		while (d > num) {
			parent[n][acs] = parent[idx][acs - 1];
			dist[n][acs] = dist[idx][acs - 1] + dist[n][acs - 1];
			idx = parent[n][acs];
			acs++;
			num <<= 1;
		}
	}

	for (auto& node : neighbor[n]) {
		if (node.first == p)
			continue;
		makeTree(node.first, d + 1, n, node.second);
	}
	return;
}

int Equal_Depth(int x, int y) {
	int diff = depth[x] - depth[y];
	vector<int> route;
	int idx = 1;
	int c = 0;
	while (diff >= idx) {
		if (diff & idx)
			route.push_back(c);
		idx <<= 1;
		c++;
	}
	for (const auto& r : route) {
		answer += dist[x][r];
		x = parent[x][r];
	}
	return x;
}

int LCA(int x, int y) {
	int idx = 0;
	int idx_x = x;
	int idx_y = y;
	int bx = x;
	int by = y;
	int before_answer = answer;
	while (bx != by) {
		idx_x = bx;
		idx_y = by;
		answer = before_answer;
		while (idx_x != idx_y) {
			before_answer = answer;
			bx = idx_x;
			by = idx_y;
			answer += dist[idx_x][idx];
			idx_x = parent[idx_x][idx];
			answer += dist[idx_y][idx];
			idx_y = parent[idx_y][idx];
			idx++;
		}
		if (idx == 1)
			break;
		idx = 0;
	}
	return answer;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		neighbor[x].push_back({ y,c });
		neighbor[y].push_back({ x,c });
	}

	makeTree(1, 0, 0, 0);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		answer = 0;
		int x, y;
		cin >> x >> y;
		if (depth[x] > depth[y])
			x = Equal_Depth(x, y);
		else if (depth[x] < depth[y])
			y = Equal_Depth(y, x);
		cout << LCA(x, y) << '\n';
	}

	return 0;
}