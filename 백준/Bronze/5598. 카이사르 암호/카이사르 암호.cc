#include <iostream>
#include <string>
using namespace std;
int main() {
	string str, answer="";
	cin >> str;
	for (const auto s : str) {
		if (s == 'A')
			answer += 'X';
		else if (s == 'B')
			answer += 'Y';
		else if (s == 'C')
			answer += 'Z';
		else
			answer += s - 3;
	}
	cout << answer;
	return 0;
}