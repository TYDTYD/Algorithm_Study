#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
using namespace std;

int find_parent(int x, vector<int>& p) {
	if (x == p[x])
		return x;
	return p[x] = find_parent(p[x], p);
}

void merge(int x, int y, vector<int>& p) {
	int x_parent = find_parent(x, p);
	int y_parent = find_parent(y, p);
	
	if (x_parent != y_parent) {
		p[y_parent] = x_parent;
	}
	return;
}

bool isOverlap(double x1, double y1, double r1, double x2, double y2, double r2) {
	double xDiff = x1 - x2;
	double yDiff = y1 - y2;
	double r = r1 + r2;
	return (r * r) >= (xDiff * xDiff + yDiff * yDiff);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> parent(n + 1);
		vector<array<int, 3>> region(n + 1);

		for (int i = 1; i <= n; i++) {
			parent[i] = i;

			int x, y, r;
			cin >> x >> y >> r;
			region[i] = { x,y,r };
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (isOverlap(region[i][0], region[i][1], region[i][2], region[j][0], region[j][1], region[j][2])) {
					if (find_parent(i, parent) != find_parent(j, parent))
						merge(i, j, parent);
				}
			}
		}

		unordered_set<int> group;
		for (int i = 1; i <= n; i++) {
			group.insert(find_parent(i, parent));
		}
		cout << group.size() << '\n';
	}

	return 0;
}