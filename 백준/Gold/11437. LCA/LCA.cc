#include <iostream>
#include <vector>
using namespace std;

int parent[100001];
int depth[100001];
vector<int> neighbor[100001];

void SetDepth(int n, int p, int d) {
	parent[n] = p;
	depth[n] = d;
	for (auto& c : neighbor[n]) {
		if (c == p)
			continue;
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
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		neighbor[x].push_back(y);
		neighbor[y].push_back(x);
	}

	SetDepth(1, 0, 0);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
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