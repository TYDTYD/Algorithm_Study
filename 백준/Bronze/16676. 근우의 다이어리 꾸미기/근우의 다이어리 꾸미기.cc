#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string numStr = to_string(n);
	string str = "";
	int answer = numStr.length();
	for (int i = 0; i < numStr.length(); i++)
		str += '1';
	
	if (n < stoi(str))
		answer -= 1;
	if(n == 0)
		answer = 1;
	cout << answer;
	return 0;
}