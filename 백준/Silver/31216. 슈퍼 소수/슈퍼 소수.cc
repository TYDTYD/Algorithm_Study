#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	vector<int> prime;
	
	for (int i = 2; prime.size() < 27450; i++) {
		bool plag = true;
		for (const auto p : prime) {
			if (i % p == 0) {
				plag = false;
				break;
			}
		}
		if (plag)
			prime.emplace_back(i);
	}

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << prime[prime[n-1]-1] << '\n';
	}
	return 0;
}