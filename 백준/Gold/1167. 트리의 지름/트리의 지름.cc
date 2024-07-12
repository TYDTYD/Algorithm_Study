#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sum = 0;
bool visited[100001] = {};
struct Node {
	Node* parent = nullptr;
	unordered_map<int, int> w_idx;
	vector<Node*> children;
	int num = 0, w = 0, first = 0, t = 0, count = 0;

	Node(int n) {
		num = n;
	}

	void plus(int cw) {
		count++;
		sum = max(sum,cw);
		
		if (count == 1) {
			if (parent == nullptr) {
				t = cw;
				first = cw;
				return;
			}
			t = cw + w_idx[parent->num];
			first = cw;
		}
		else {
			if (parent == nullptr) {
				t = max(t, cw);
				sum = max(sum, first + cw);
				first = max(first, cw);
				return;
			}
			t = max(t, cw + w_idx[parent->num]);
			sum = max(sum, first + cw);
			first = max(first, cw);
		}
		sum = max(sum, t);
		if (count == children.size()-1)
			parent->plus(t);

		return;
	}

	void travle_leaf() {
		if (children.size() == 1 && visited[children[0]->num])
			parent->plus(w_idx[parent->num]);
		for (const auto& c : children) {
			visited[num] = true;
			if (!visited[c->num]) {
				c->parent = this;
				c->travle_leaf();
			}
		}
		return;
	}
};

int main() {
	unordered_map<int, Node*> node_idx;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	Node* root = nullptr;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if(node_idx.find(p)==node_idx.end())
			node_idx[p] = new Node(p);
		if (i == 0)
			root = node_idx[p];
		int c, weight = 0;
		while (true) {
			cin >> c;
			if (c == -1)
				break;
			cin >> weight;
			if(node_idx.find(c)==node_idx.end())
				node_idx[c] = new Node(c);
			node_idx[p]->w_idx[c] = weight;
			node_idx[p]->children.push_back(node_idx[c]);
		}
	}
	root->travle_leaf();
	cout << sum;
	return 0;
}