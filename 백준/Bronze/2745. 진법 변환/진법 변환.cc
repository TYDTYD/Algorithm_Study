#include <iostream>
#include <string>
using namespace std;

int main() {
	int b;
	string n;
	cin >> n >> b;
	int answer = 0;

	for (int i = 0; i < n.length(); i++) {
		char c = n[i];
		int digit;
		if (c >= '0' && c <= '9')
			digit = c - '0';
		else
			digit = c - 55;
		
		for (int j = n.length() - 1; j > i; j--)
			digit *= b;
		answer = answer + digit;
	}

	cout << answer;

	return 0;
}