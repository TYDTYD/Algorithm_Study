#include <iostream>
#include <vector>
using namespace std;

int find_parent(int p, vector<int>& graph) {
	if (p == graph[p])
		return p;
	return graph[p] = find_parent(graph[p], graph);
}

void merge(int x,int y, vector<int>& graph) {
	int x_parent = find_parent(x, graph);
	int y_parent = find_parent(y, graph);

	if (x_parent > y_parent) {
		graph[y_parent] = x_parent;
		find_parent(y, graph);
	}
	else {
		graph[x_parent] = y_parent;
		find_parent(x, graph);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> parent(n + 1);

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c) {
			if (find_parent(a, parent) == find_parent(b, parent))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
		else {
			merge(a, b, parent);
		}
	}

	return 0;
}