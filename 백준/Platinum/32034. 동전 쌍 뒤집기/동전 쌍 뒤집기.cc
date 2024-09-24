#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		stack<pair<char,long long>> stk;
		long long n, pos = 0, answer = 0;
		bool stacked = false;
		string str;
		cin >> n >> str;
		for (const auto& s : str) {
			pair<char,int> t;
			if (!stk.empty()) {
				t = stk.top();
				stacked = true;
			}
			else
				stacked = false;
			stk.push({s,pos++});
			if (stacked) {
				if (stk.top().first == 'H') {
					if (t.first == s) {
						stk.pop();
						stk.pop();
					}
				}
				else {
					if (t.first == 'T') {
						answer += stk.top().second - t.second;
						stk.pop();
						stk.pop();
					}
				}
			}
			else {
				if (s == 'H')
					stk.pop();
			}
		}
		while (!stk.empty()) {
			if (stk.top().first == 'T')
				answer = -1;
			stk.pop();
		}
		cout << answer << '\n';
	}
	return 0;
}