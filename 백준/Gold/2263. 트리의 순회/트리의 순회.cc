#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	int value = 0;

	Node(int v) {
		value = v;
	}

	void printPreOrder() {
		cout << value << ' ';
		if (left != nullptr)
			left->printPreOrder();
		if (right != nullptr)
			right->printPreOrder();
	}
};

vector<int> inOrder, postOrder;
unordered_map<int, int> hash_idx;

int findRoot(int value) {
	auto it = hash_idx.find(value);
	if (it != hash_idx.end())
		return hash_idx[value];
	return -1;
}

void build_BT(Node& n, int first, int mid, int end, int idx) {
	if (mid == end && mid == first)
		return;
	if (mid > end || mid < first)
		return;
	int rightroot = -1;
	int leftroot = -1;
	
	Node* rightRoot = nullptr;
	if (postOrder.size() > idx+1 && mid!=end) {
		rightroot = postOrder[idx+1];
		rightRoot = new Node(rightroot);
		n.right = rightRoot;
	}
	int rightPos = findRoot(rightroot);
	int posNum = end - mid;
	Node* leftRoot = nullptr;
	if (postOrder.size() > idx+posNum+1 && mid!=first) {
		leftroot = postOrder[idx + posNum+1];
		leftRoot = new Node(leftroot);
		n.left = leftRoot;
	}
	int leftPos = findRoot(leftroot);
	if (first <= leftPos && leftPos <= mid && leftRoot!=nullptr)
		build_BT(*leftRoot, first, leftPos, mid-1, idx+posNum+1);
	if(mid <= rightPos && rightPos <= end && rightRoot!=nullptr)
		build_BT(*rightRoot, mid+1, rightPos, end, idx+1);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, root_Value;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		inOrder.push_back(v);
		hash_idx[v] = i;
	}
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		postOrder.push_back(v);
		root_Value = v;
	}
	Node* root = new Node(root_Value);
	reverse(postOrder.begin(), postOrder.end());
	if (n == 1) {
		cout << root->value;
		return 0;
	}
	else if (n == 2) {
		for (const auto& i : postOrder)
			cout << i << ' ';
		return 0;
	}
	int leftPos = -1, rightPos = -1;
	int pos = findRoot(root_Value);
	Node* rightRoot = nullptr;
	if (root_Value != inOrder.back()) {
		rightPos = findRoot(postOrder[1]);
		rightRoot = new Node(postOrder[1]);
		root->right = rightRoot;
	}
	int posnum = n - pos;
	Node* leftRoot = nullptr;
	if (postOrder.size() > posnum) {
		leftPos = findRoot(postOrder[posnum]);
		leftRoot = new Node(postOrder[posnum]);
		root->left = leftRoot;
	}
	build_BT(*leftRoot, 0, leftPos, pos - 1, posnum);
	build_BT(*rightRoot, pos+1, rightPos, n-1, 1);
	root->printPreOrder();

	return 0;
}