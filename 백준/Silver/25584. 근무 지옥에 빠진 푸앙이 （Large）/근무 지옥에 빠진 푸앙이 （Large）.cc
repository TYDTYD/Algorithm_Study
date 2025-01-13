#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	unordered_map<string, int> worker;
	int mn = 1e9, mx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 7; k++) {
				string s;
				cin >> s;
				if (s != "-") {
					switch (j) {
					case 0:
						worker[s] += 4;
						break;
					case 1:
						worker[s] += 6;
						break;
					case 2:
						worker[s] += 4;
						break;
					case 3:
						worker[s] += 10;
						break;
					}
				}
			}
		}
	}

	for (const auto& w : worker) {
		mn = min(w.second, mn);
		mx = max(w.second, mx);
	}

	cout << ((mx - mn <= 12) ? "Yes" : "No");
	return 0;
}