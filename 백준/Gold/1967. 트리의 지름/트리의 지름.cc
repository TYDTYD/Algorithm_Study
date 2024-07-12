#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sum = 0;
struct Node {
	Node* parent = nullptr;
	vector<Node*> children;
	int num = 0, w = 0, first = 0, t = 0, count = 0;

	Node(int n) {
		num = n;
	}

	void plus(int cw) {
		count++;
		if (count == 1) {
			t = cw + w;
			first = cw;
		}
		else {
			t = max(t, cw + w);
			sum = max(sum, first + cw);
			first = max(first, cw);
		}
		sum = max(sum, t);
		
		if (parent == nullptr)
			return;
		if (count == children.size())
			parent->plus(t);

		return;
	}

	void travle_leaf() {
		if (children.empty())
			parent->plus(w);
		for (const auto& c : children)
			c->travle_leaf();
		return;
	}
};

int main() {
	unordered_map<int, Node*> node_idx;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	Node* root = new Node(1);
	node_idx[1] = root;
	for (int i = 1; i < n; i++) {
		int a, b, weight;
		cin >> a >> b >> weight;
		if (node_idx.find(a) == node_idx.end())
			node_idx[a] = new Node(a);
		if (node_idx.find(b) == node_idx.end())
			node_idx[b] = new Node(b);
		node_idx[b]->w = weight;
		node_idx[b]->parent = node_idx[a];
		node_idx[a]->children.push_back(node_idx[b]);
	}
	root->travle_leaf();
	cout << sum;
	return 0;
}