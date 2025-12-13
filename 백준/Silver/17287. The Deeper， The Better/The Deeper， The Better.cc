#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int answer = 0;
	int result = 0;

	for (char c : s) {
		if (c == '(')
			result += 1;		
		else if (c == '{')
			result += 2;				
		else if (c == '[')
			result += 3;					
		if (c == ')')
			result -= 1;		
		else if (c == '}')
			result -= 2;		
		else if (c == ']')
			result -= 3;	

		if(c >= '0' && c <= '9')
			answer = max(answer, result);
	}
	cout << answer;
	return 0;
}