#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (auto& str : s) {
			if (str < 97)
				str += 32;
		}
		cout << s << '\n';
	}
	return 0;
}