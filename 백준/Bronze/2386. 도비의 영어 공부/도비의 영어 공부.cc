#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	char c;
	string str;
	while (true) {
		cin >> c;
		if (c == '#')
			break;
		getline(cin, str);
		unordered_map<int, int> charCount;
		for (char ch : str)
			charCount[ch - 0]++;
		cout << c << ' ' << charCount[c] + charCount[c - 32] << '\n';
	}
	return 0;
}