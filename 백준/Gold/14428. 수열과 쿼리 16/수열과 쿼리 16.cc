#include <iostream>
#define INF 1e9+1
using namespace std;

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	int value = INF;
	int index = INF;
	int lValue, rValue;
	Node(int v, int lvalue, int rvalue) {
		value = v;
		lValue = lvalue;
		rValue = rvalue;
	}
	Node() {}

	void Insert(int i, int value) {
		if (value == this->value)
			this->index = min(i, this->index);
		else if (value < this->value) {
			this->value = value;
			this->index = i;
		}
		if (left != nullptr && i >= left->lValue && i <= left->rValue)
			left->Insert(i, value);
		if (right != nullptr && i >= right->lValue && i <= right->rValue)
			right->Insert(i, value);
		return;
	}

	void Modify(int i, int value) {
		if (lValue == rValue && i == index) {
			this->value = value;
			return;
		}
		if (left != nullptr && i >= left->lValue && i <= left->rValue){
			left->Modify(i, value);
			if (right != nullptr) {
				if (left->value == right->value) {
					this->index = min(left->index, right->index);
					this->value = left->value;
				}
				else {
					if (left->value > right->value)
						this->index = right->index;
					else if (left->value < right->value)
						this->index = left->index;
					else
						this->index = min(left->index, right->index);
					this->value = min(left->value, right->value);
				}
			}
			else {
				if (left->value == this->value) {
					this->index = min(left->index, this->index);
				}
				else {
					if (left->value < this->value)
						this->index = left->index;
					else if (left->value == this->value)
						this->index = min(left->index, this->index);
					this->value = min(left->value, this->value);
				}
			}
		}
		if (right != nullptr && i >= right->lValue && i <= right->rValue){
			right->Modify(i, value);
			if (left != nullptr) {
				if (right->value == left->value) {
					this->index = min(left->index, right->index);
					this->value = left->value;
				}
				else {
					if (left->value > right->value)
						this->index = right->index;
					else if (left->value < right->value)
						this->index = left->index;
					else
						this->index = min(left->index, right->index);
					this->value = min(left->value, right->value);
				}
			}
			else {
				if (right->value == this->value) {
					this->index = min(right->index, this->index);
				}
				else {
					if (right->value < this->value)
						this->index = right->index;
					else if (right->value == this->value)
						this->index = min(right->index, this->index);
					this->value = min(right->value, this->value);
				}
			}
		}
		return;
	}

	pair<int, int> Find(int l, int r) {
		pair<int, int> leftValue = { INF,INF };
		pair<int, int> rightValue = { INF,INF };
		if (l <= lValue && r >= rValue)
			return { value,index };
		if (left != nullptr && l <= left->rValue)
			leftValue = left->Find(l, r);
		if (right != nullptr && r >= right->lValue)
			rightValue = right->Find(l, r);
		if (leftValue.first < rightValue.first)
			return leftValue;
		else if (leftValue.first > rightValue.first)
			return rightValue;
		else {
			if (leftValue.second < rightValue.second)
				return leftValue;
			else
				return rightValue;
		}
	}
};

void MakeSegTree(Node& node, int l, int r) {
	node.lValue = l;
	node.rValue = r;
	if (l == r)
		return;
	int offset = (r - l) / 2;
	Node* leftNode = new Node();
	Node* rightNode = new Node();
	node.left = leftNode;
	node.right = rightNode;
	MakeSegTree(*node.left, l, l + offset);
	MakeSegTree(*node.right, l + offset + 1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	Node tree;
	cin >> n;
	MakeSegTree(tree, 1, n);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		tree.Insert(i, a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 1)
			tree.Modify(a, b);
		else
			cout << tree.Find(a, b).second << '\n';
	}
	return 0;
}