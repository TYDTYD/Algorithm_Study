#include <iostream>
#include <string>
#define div 1000000
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int result[5010] = {};
	result[0] = 1;
	string input;
	cin >> input;
	int n = input.size();

	if (input[0] == '0') {
		cout << 0;
		return 0;
	}

	if (n == 1) {
		cout << 1;
		return 0;
	}
	
	
	for (int i = 1; i <= n; i++) {
		if ( (input[i-1]-'0') >= 1 && (input[i-1]-'0') <= 9)
			result[i] += result[i - 1] % div;
		if (i == 1)
			continue;
		int tmp = (input[i-1] - '0') + (input[i - 2] - '0') * 10;
		if (tmp >= 10 && tmp <= 26)
			result[i] = (result[i - 2] + result[i]) % div;
	}
	int answer = result[n] % div;
	cout << answer;
	return 0;
}