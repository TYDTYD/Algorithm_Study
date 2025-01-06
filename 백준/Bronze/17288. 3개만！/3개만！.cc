#include <iostream>
#include <string>
using namespace std;

int main() {
	int answer = 0, count = 0;
	bool more = false;
	string s;
	cin >> s;
	for (int i = 0; i < s.length()-1; i++) {
		if ((s[i] - '0') + 1 == s[i + 1] - '0')
			count++;
		else {
			count = 0;
			more = false;
		}
		if (count == 2)
			answer++;
		if (count >= 3) {
			if (!more)
				answer--;
			more = true;
		}
	}

	cout << answer;
	return 0;
}