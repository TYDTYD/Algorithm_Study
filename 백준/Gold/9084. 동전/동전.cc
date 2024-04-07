#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, money;
		vector<int> coin;
		int result[20001] = {};
		result[0] = 1;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int c;
			cin >> c;
			coin.push_back(c);
		}
		cin >> money;
		for (const auto& c:coin) {
			for (int j = 0; j <= money; j++) {
				if (j - c < 0)
					continue;
				result[j] += result[j - c];
			}
		}
		
		cout << result[money] << '\n';
	}


	return 0;
}