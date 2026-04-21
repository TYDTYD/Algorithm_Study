#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string n;
		cin >> n;
		int index = 1;
		long long num = stoll(n);
		reverse(n.begin(), n.end());
		long long rev_num = stoll(n);
		if ((sqrt(num) - int(sqrt(num)) == 0) && sqrt(rev_num) - int(sqrt(rev_num)) == 0)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	
	return 0;
}