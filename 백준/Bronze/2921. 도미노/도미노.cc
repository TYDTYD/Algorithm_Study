#include <iostream>
using namespace std;

int main() {
	int n, answer = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		answer += (2 * i * (2 * i + 1) / 2) - (i * (i - 1) / 2);
	cout << answer;
	return 0;
}