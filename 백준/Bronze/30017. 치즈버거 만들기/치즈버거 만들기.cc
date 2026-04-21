#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int answer = (a - 1 >= b) ? 2 * b + 1 : 2 * (a - 1) + 1;
	cout << answer;
	return 0;
}