#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long case1 = 0, case2 = 0;
	bool pass1 = true, pass2 = false;
	for (int i = 0; i < n; i++) {
		long long c;
		cin >> c;
		if (c) {
			pass1 = true;
			pass2 = true;
		}
		else {
			if (pass1 && i!=n-1) {
				case1++;
				pass1 = false;
			}
			else {
				pass1 = true;
			}
			if (pass2) {
				case2++;
				pass2 = false;
			}
			else {
				pass2 = true;
			}
		}
		case1 += c;
		case2 += c;
	}

	cout << max(case1, case2);

	return 0;
}