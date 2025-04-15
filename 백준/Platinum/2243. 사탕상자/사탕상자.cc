#include <iostream>
using namespace std;

struct Candy {
	int parent;
	int start;
	int end;
	int index = 0;
};

Candy Tree[4000001];

void MakeSegTree(int start, int end, int i) {
	Tree[i].start = start;
	Tree[i].end = end;
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	MakeSegTree(start, mid, i * 2);
	MakeSegTree(mid + 1, end, i * 2 + 1);
}

void UpdateTree(int i, int idx, int start, int end, int amount) {
	if (idx < start || idx > end)
		return;
	Tree[i].index += amount;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	UpdateTree(i * 2, idx, start, mid, amount);
	UpdateTree(i * 2 + 1, idx, mid + 1, end, amount);
}

int ReturnIndex(int i, int idx) {
	if (Tree[i].start == Tree[i].end)
		return Tree[i].start;
	if (idx > Tree[i * 2].index)
		return ReturnIndex(i * 2 + 1, idx - Tree[i * 2].index);
	else
		return ReturnIndex(i * 2, idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	MakeSegTree(1, 1000000, 1);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			cin >> b;
			int candyType = ReturnIndex(1, b);
			cout << candyType << '\n';
			UpdateTree(1, candyType, 1, 1000000, -1);
		}
		else {
			int b, c;
			cin >> b >> c;
			UpdateTree(1, b, 1, 1000000, c);
		}
	}

	return 0;
}