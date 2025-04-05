#include <iostream>
#include <vector>
using namespace std;

vector<int> neighbor[100001];
int parent[100001][20];
int depth[100001];

void makeTree(int n, int d, int p) {
	depth[n] = d;
	if (n != 1) {
		parent[n][0] = p;
		int idx = parent[n][0];
		int acs = 1;
		int num = 1;
		while (d > num) {
			parent[n][acs] = parent[idx][acs - 1];
			idx = parent[n][acs];
			acs++;
			num <<= 1;
		}
	}
	
	for (auto& node : neighbor[n]) {
		if (node == p)
			continue;
		makeTree(node, d + 1, n);
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
	while (bx != by) {
		idx_x = bx;
		idx_y = by;
		while (idx_x != idx_y) {
			bx = idx_x;
			by = idx_y;
			idx_x = parent[idx_x][idx];
			idx_y = parent[idx_y][idx];
			idx++;
		}
		if (idx == 1) {
			x = idx_x;
			break;
		}
		idx = 0;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		neighbor[x].push_back(y);
		neighbor[y].push_back(x);
	}

	int m;
	cin >> m;

	makeTree(1, 0, 0);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		int x_depth = depth[x];
		int y_depth = depth[y];
		if (x_depth > y_depth)
			x = Equal_Depth(x, y);
		else if (x_depth < y_depth)
			y = Equal_Depth(y, x);
		if (x == y)
			cout << x << '\n';
		else
			cout << LCA(x, y) << '\n';
	}
	return 0;
}