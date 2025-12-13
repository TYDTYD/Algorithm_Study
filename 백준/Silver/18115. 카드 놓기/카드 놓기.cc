#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<int> commands;
	deque<int> result;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		commands.push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		int command = commands.back();
		commands.pop_back();
		switch (command) {
		case 1:
			result.push_front(i);
			break;
		case 2: {
			int idx = result.front();
			result.pop_front();
			result.push_front(i);
			result.push_front(idx);
			break;
		}
		case 3:
			result.push_back(i);
			break;
		}
	}

	for (const auto& r : result)
		cout << r << ' ';

	return 0;
}