#include <iostream>
#include <vector>
#include <algorithm>
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

int findRoot(int l,int r, int value) {
	if (r > inOrder.size())
		r = inOrder.size();
	for (int i = l; i < r; i++) {
		if (value == inOrder[i])
			return i;
	}
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
	int rightPos = findRoot(mid, end+1, rightroot);
	int posNum = end - mid;
	Node* leftRoot = nullptr;
	if (postOrder.size() > idx+posNum+1 && mid!=first) {
		leftroot = postOrder[idx + posNum+1];
		leftRoot = new Node(leftroot);
		n.left = leftRoot;
	}
	int leftPos = findRoot(first, mid+1, leftroot);
	if (first <= leftPos && leftPos <= mid && leftRoot!=nullptr)
		build_BT(*leftRoot, first, leftPos, mid-1, idx+posNum+1);
	if(mid <= rightPos && rightPos <= end && rightRoot!=nullptr)
		build_BT(*rightRoot, mid+1, rightPos, end, idx+1);
	return;
}

int main() {
	int n, root_Value;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		inOrder.push_back(v);
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
	// build_BT 왼쪽 오른쪽 두개로 만들어서 풀기
	// 포스트오더는 마지막이 루트 노드임
	int leftPos = -1, rightPos = -1;
	int pos = findRoot(0, n, root_Value); // 루트 위치
	Node* rightRoot = nullptr;
	if (root_Value != inOrder.back()) {
		rightPos = findRoot(pos, n, postOrder[1]);
		rightRoot = new Node(postOrder[1]);
		root->right = rightRoot;
	}
	
	int posnum = n - pos; // 오른쪽 서브트리의 개수
	// 왼쪽 서브트리 루트의 값
	Node* leftRoot = nullptr;
	if (postOrder.size() > posnum) {
		leftPos = findRoot(0, pos, postOrder[posnum]);
		leftRoot = new Node(postOrder[posnum]);
		root->left = leftRoot;
	}
	
	// 왼쪽 오른쪽 서브트리 각각 실행
	build_BT(*leftRoot, 0, leftPos, pos - 1, posnum);
	build_BT(*rightRoot, pos+1, rightPos, n-1, 1);
	root->printPreOrder();

	return 0;
}