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
		cin >> n;
		vector<int> coin(n,0);
		int result[20001] = {};
		result[0] = 1;
		
		for (int j = 0; j < n; j++)
			cin >> coin[j];
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