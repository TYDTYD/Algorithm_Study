#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin, s);
	int answer = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A')
			answer += 1;
		if (s[i] == 'a')
			answer += 1;
		if (s[i] == 'B')
			answer += 2;
		if (s[i] == 'b')
			answer += 1;
		if (s[i] == 'D')
			answer += 1;
		if (s[i] == 'd')
			answer += 1;
		if (s[i] == 'e')
			answer += 1;
		if (s[i] == 'g')
			answer += 1;
		if (s[i] == 'O')
			answer += 1;
		if (s[i] == 'o')
			answer += 1;
		if (s[i] == 'Q')
			answer += 1;
		if (s[i] == 'q')
			answer += 1;
		if (s[i] == 'R')
			answer += 1;
		if (s[i] == 'P')
			answer += 1;
		if (s[i] == 'p')
			answer += 1;
		if (s[i] == '@')
			answer += 1;
	}
	cout << answer;

	return 0;
}