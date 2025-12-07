#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str = to_string(n);

	int total = 1;

	for (int i = 0; i < str.length(); i++) {
		total *= (str[i] - '0');
	}

	int front = 1;
	int back = total;

	for (int i = 0; i < str.length() - 1; i++) {
		front *= (str[i] - '0');
		if (str[i] - '0' == 0) {
			back = 1;
			for(int j = i + 1; j < str.length(); j++) {
				back *= (str[j] - '0');
			}
		}
		else {
			back /= (str[i] - '0');
		}			
		
		if (front == back) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}