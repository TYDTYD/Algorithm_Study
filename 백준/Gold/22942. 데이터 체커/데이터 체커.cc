#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

struct CircleInfo {
	int pos;
	int number;
	bool isFront;

	CircleInfo(int p, int n, bool plag) : pos(p), number(n), isFront(plag) {}
};

bool CircleCompare(const CircleInfo& x, const CircleInfo& y) {
	return x.pos < y.pos;
}

int main() {
	int n;
	cin >> n;
	vector<CircleInfo> circleInfos;
	unordered_set<int> pos_check;

	for (int i = 0; i < n; i++) {
		int x, r;
		cin >> x >> r;
		circleInfos.push_back(CircleInfo(x - r, i, true));
		circleInfos.push_back(CircleInfo(x + r, i, false));
		pos_check.insert(x - r);
		pos_check.insert(x + r);
	}

	if (pos_check.size() != 2 * n) {
		cout << "NO";
		return 0;
	}

	sort(circleInfos.begin(), circleInfos.end(), CircleCompare);
	stack<int> stk;

	for (const auto& info : circleInfos) {
		if (info.isFront) {
			stk.push(info.number);
		}
		else {
			if (stk.top() == info.number)
				stk.pop();
			else
				break;
		}
	}

	if (stk.empty()) 
		cout << "YES";
	else
		cout << "NO";

	return 0;
}