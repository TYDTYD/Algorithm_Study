#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long double n;
	int answer = 0;
	cin >> n;
	while (n > 1) {
		answer++;
		n /= (long double)2;
	}
	cout << answer+1;
	return 0;
}