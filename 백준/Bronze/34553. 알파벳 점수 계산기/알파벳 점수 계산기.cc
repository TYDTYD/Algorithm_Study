#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	bool isFirst = true;
	int answer = 0;
	int score = 0;
	char beforeChar = s[0];
	for (const auto& c : s) {
		if (isFirst) {
			isFirst = false;
			answer++;
			score = 1;
			continue;
		}
		if(c > beforeChar) {
			score++;
			answer += score;			
		}
		else {
			score = 1;
			answer++;
		}

		beforeChar = c;
	}

	cout << answer;
	return 0;
}