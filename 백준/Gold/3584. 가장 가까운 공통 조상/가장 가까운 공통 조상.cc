#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];
int depth[10001];
vector<int> neighbor[10001];

void SetDepth(int n, int p, int d) {
	parent[n] = p;
	depth[n] = d;
	for (auto& c : neighbor[n]) {
		SetDepth(c, n, d + 1);
	}
	return;
}

int LCA(int x, int y) {
	while (depth[x] != depth[y])
		x = parent[x];
	while (x != y) {
		x = parent[x];
		y = parent[y];
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		fill(parent, parent + n, 0);
		fill(depth, depth + n, 0);
		for (int i = 0; i < n; i++)
			neighbor[i].clear();

		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			neighbor[x].push_back(y);
			parent[y] = x;
		}

		int root = 0;
		for (int i = 1; i <= n; i++) {
			if (parent[i] == 0) {
				root = i;
				break;
			}
		}

		SetDepth(root, 0, 0);

		int x, y;
		cin >> x >> y;
		if (depth[x] > depth[y])
			cout << LCA(x, y) << '\n';
		else if (depth[x] < depth[y])
			cout << LCA(y, x) << '\n';
		else
			cout << LCA(x, y) << '\n';
	}
	
	return 0;
}