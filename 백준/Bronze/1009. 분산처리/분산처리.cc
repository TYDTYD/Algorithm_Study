#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int a, b, answer;
		cin >> a >> b;
		int result = 1;
		for (int i = 0; i < b; i++) {
			result *= (a % 10);
			result %= 10;
		}
		if (!result)
			result += 10;
		cout << result << '\n';
	}
	return 0;
}