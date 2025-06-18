#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long result[3];
		result[0] = (a + b) * (a + b) + c * c;
		result[1] = (a + c) * (a + c) + b * b;
		result[2] = (b + c) * (b + c) + a * a;
		cout << *min_element(result,result+3) << '\n';
	}
	return 0;
}