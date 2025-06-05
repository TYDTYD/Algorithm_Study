#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int find_parent(vector<int>& v, int p) {
	if (v[p] == p)
		return p;
	return v[p] = find_parent(v, v[p]);
}

void merge(int x, int y, vector<int>& parent, unordered_set<int> z) {
	int parent_x = find_parent(parent, x);
	int parent_y = find_parent(parent, y);

	if (parent_x != parent_y) {
		if (z.find(parent_x) != z.end())
			parent[parent_y] = parent_x;
		else if (z.find(parent_y) != z.end())
			parent[parent_x] = parent_y;
		else
			parent[parent_y] = parent_x;
	}
}

struct Rect {
	double x1, y1, x2, y2;
	Rect(double _x1, double _y1, double _x2, double _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

bool rectCheck(Rect& r1, Rect& r2) {
	if (r1.x2 < r2.x1)
		return true;
	if (r1.y2 < r2.y1)
		return true;
	if (r2.y2 < r1.y1)
		return true;
	if (r1.x1 < r2.x1 && r1.x2 > r2.x2 && r1.y1 < r2.y1 && r1.y2 > r2.y2)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, answer = 0;
	unordered_set<int> number;
	unordered_set<int> zero;
	cin >> n;

	vector<int> parent(n);
	vector<Rect> rect;

	for (int i = 0; i < n; i++) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 <= 0 && y1 == 0 && x2 >= 0)
			zero.insert(i);
		else if (x1 == 0 && y1 < 0 && y2>0)
			zero.insert(i);
		else if (x1 < 0 && y1 < 0 && x2 == 0 && y2>=0)
			zero.insert(i);
		parent[i] = i;
		rect.push_back(Rect(x1, y1, x2, y2));
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool plag = (rect[i].x1 <= rect[j].x1) ? rectCheck(rect[i], rect[j]) : rectCheck(rect[j], rect[i]);
			if (!plag) {
				merge(i, j, parent, zero);
			}
		}
	}


	for (int i = 0; i < n; i++) {
		int e = find_parent(parent, i);
		if (zero.find(e) == zero.end())
			number.insert(parent[e]);
	}

	cout << number.size();

	return 0;
}